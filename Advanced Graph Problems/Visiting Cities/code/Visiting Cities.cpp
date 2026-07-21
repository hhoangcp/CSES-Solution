
#include <iostream>
#include <algorithm>
#include <vector>
#define llong long long

using namespace std;

struct TEdge {
    int u, v, cost;
} E[200006];

llong dist[100006];
int pos[100006], head[100006], link[200006];
int heap[100006], nheap = 0;

void Up_heap(int u) {
    if (pos[u] == 0) heap[++nheap] = u, pos[u] = nheap;

    for(int cur = pos[u]; cur > 1; cur >>= 1) {
        int par = (cur >> 1);
        if (dist[heap[cur]] >= dist[heap[par]]) break;

        swap(pos[heap[cur]], pos[heap[par]]);
        swap(heap[cur], heap[par]);
    }
}

int Top_pop_heap() {
    int u = heap[1]; pos[heap[1]] = 0;
    heap[1] = heap[nheap--];
    if (nheap == 0) return u;
    pos[heap[1]] = 1;

    for(int par = 1; (par << 1) <= nheap; par <<= 1) {
        int cur = (par << 1);
        if (cur < nheap && dist[heap[cur]] > dist[heap[cur+1]]) ++cur;
        if (dist[heap[cur]] >= dist[heap[par]]) break;

        swap(pos[heap[cur]], pos[heap[par]]);
        swap(heap[cur], heap[par]);

        par = cur;
    }

    return u;
}

int n, m;

void Dijkstra(int s, int t) {
    nheap = 0;
    for(int u = 1; u <= n; ++u) pos[u] = 0, dist[u] = 2e18;

    dist[s] = 0; Up_heap(1);
    while (nheap > 0) {
        int u = Top_pop_heap();

        for(int i = head[u]; i > 0; i = link[i]) {
            int v = E[i].v;

            if (dist[v] > dist[u] + E[i].cost) {
                dist[v] = dist[u] + E[i].cost;
                Up_heap(v);
            }
        }
    }
}

vector<int> V[100006], Bucket[100006], Tree[100006], V_rev[100006];
int num[100006], sdom[100006], dom[100006], lab[100006], par[100006], dsu[100006];

int Find(int u, int x = 0) {
    if (u == dsu[u]) return x ? -1 : u;

    int v = Find(dsu[u], x+1);
    if (v < 0) return u;

    if (sdom[lab[u]] > sdom[lab[dsu[u]]])
        lab[u] = lab[dsu[u]];

    dsu[u] = v;
    return x ? v : lab[u];
}

void Union(int u, int v) {
    dsu[v] = u;
}

void DFS(int u) {
    num[u] = ++num[0]; pos[num[0]] = u;
    lab[num[0]] = sdom[num[0]] = dsu[num[0]] = num[0];

    for(int v: V[u]) {
        if (!num[v]) {
            DFS(v);
            par[num[v]] = num[u];
        }

        V_rev[num[v]].push_back(num[u]);
    }
}

int trace[100006];
bool tick[100006];

void DFS2(int u) {
    tick[u] = true;
    if (u == n) return;

    for(int v: Tree[u])
    if (!tick[v]) {
        trace[v] = u;
        DFS2(v);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int u, v, cost; cin >> u >> v >> cost;
        E[i] = {u, v, cost};
        link[i] = head[u]; head[u] = i;
    }

    Dijkstra(1, n);
    for(int u = 1; u < n; ++u)
    for(int i = head[u]; i > 0; i = link[i]) {
        int v = E[i].v;

        if (dist[v] == dist[u] + E[i].cost) V[u].push_back(v);
    }

    fill(pos, pos+n+1, 0);
    DFS(1);

    for(int i = num[0]; i >= 1; --i) {
        for(int v: V_rev[i]) sdom[i] = min(sdom[i], sdom[Find(v)]);

        if (i > 1) Bucket[sdom[i]].push_back(i);

        for(int v: Bucket[i]) {
            int u = Find(v);

            if (sdom[u] == sdom[v]) dom[v] = sdom[v];
            else dom[v] = u;
        }

        if (i > 1) Union(par[i], i);
    }

    for(int u = 2; u <= num[0]; ++u) {
        if (sdom[u] != dom[u]) dom[u] = dom[dom[u]];

        Tree[pos[u]].push_back(pos[dom[u]]);
        Tree[pos[dom[u]]].push_back(pos[u]);
    }

    DFS2(1);

    int t = n, ans = 1; fill(tick, tick+n+1, false);
    while (t != 1) {
        tick[t] = true;
        t = trace[t];
        ++ans;
    }

    cout << ans << '\n' << 1 << ' ';
    for(int u = 2; u <= n; ++u)
    if (tick[u]) cout << u << ' ';

    return 0;
}
