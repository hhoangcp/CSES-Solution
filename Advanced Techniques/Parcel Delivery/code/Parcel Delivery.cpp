
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

struct TEdge {
    int u, v, cost;
    int cap, flow;
} E[2008];

llong del[1006], dist[1006];
int n, m, M = 0, K, link[2008], head[506];
int Heap[506], nheap, pos[506];
int trace[506];

void Add_edge(int u, int v, int cost, int cap) {
    E[M] = {u, v, cost, cap, 0};
    link[M] = head[u]; head[u] = M++;

    E[M] = {v, u, -cost, 0, 0};
    link[M] = head[v]; head[v] = M++;
}

llong wp(int i) {
    return 1LL * E[i].cost + del[E[i].u] - del[E[i].v];
}

void UpHeap(int u) {
    if (pos[u] == 0) pos[u] = ++nheap, Heap[nheap] = u;

    for(int c = pos[u], p = c >> 1; p > 0; c = p, p >>= 1) {
        if(dist[Heap[p]] <= dist[Heap[c]]) break;

        swap(pos[Heap[p]], pos[Heap[c]]);
        swap(Heap[p], Heap[c]);
    }
}

int Pop_DownHeap() {
    int u = Heap[1]; pos[u] = 0;
    Heap[1] = Heap[nheap--];

    if (nheap == 0) return u;

    pos[Heap[1]] = 1;
    for(int p = 1, c = 2; c <= nheap; p = c, c <<= 1) {
        if (c < nheap && dist[Heap[c+1]] < dist[Heap[c]]) ++c;
        if(dist[Heap[p]] <= dist[Heap[c]]) break;

        swap(pos[Heap[p]], pos[Heap[c]]);
        swap(Heap[p], Heap[c]);
    }

    return u;
}

bool Dijkstra(int s) {
    nheap = 0;
    for(int u=1; u<=n; ++u) dist[u] = 1e18, pos[u] = trace[u] = 0;

    dist[n-1] = 0; UpHeap(n-1);
    while (nheap > 0) {
        int u = Pop_DownHeap();

        for(int i = head[u]; i > -1; i = link[i]) {
            int v = E[i].v;

            if (E[i].cap > E[i].flow && dist[v] > dist[u] + wp(i)) {
                dist[v] = dist[u] + wp(i);
                trace[v] = u;
                UpHeap(v);
            }
        }
    }

    return dist[n] < 1e18;
}

llong min_cost = 0;
int ptr[506];

int DFS(int u, int min_flow) {
    if (u == n) return min_flow;

    for(int &i = ptr[u]; i > -1; i = link[i]) {
        int v = E[i].v;

        if (trace[v] == u && E[i].cap > E[i].flow && dist[v] == dist[u] + wp(i)) {
            int flow = DFS(v, min(min_flow, E[i].cap - E[i].flow));
            if (flow != 0) {
                E[i].flow += flow;
                E[i^1].flow -= flow;
                min_cost += 1LL * flow * E[i].cost;
                return flow;
            }
        }
    }

    return 0;
}

void MinCost_MaxFlow() {
    if (!Dijkstra(n-1)) {
        cout << -1;
        return;
    }


    int max_flow = 0;
    do {
        for(int u=1; u<=n; ++u) ptr[u] = head[u];

        while (true) {
            int flow = DFS(n-1, 1000000000);
            if (flow == 0) break;

            max_flow += flow;
        }

        for(int u=1; u<=n; ++u)
        if (dist[u] < 1e18) del[u] += dist[u];
    } while (Dijkstra(n-1));

    if (max_flow < K) cout << -1;
    else cout << min_cost;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> m >> K;

    n += 2;
    for(int u=1; u<=n; ++u) head[u] = -1;

    Add_edge(n-1, 1, 0, K);
    Add_edge(n-2, n, 0, K);

    for(int i=1; i<=m; ++i) {
        int u, v, cap, cost; cin >> u >> v >> cap >> cost;
        Add_edge(u, v, cost, cap);
    }

    MinCost_MaxFlow();

    return 0;
}
