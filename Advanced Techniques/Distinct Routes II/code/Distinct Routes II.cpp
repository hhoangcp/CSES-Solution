
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#define llong long long

using namespace std;

struct TEdge {
    int u, v, cap, flow, cost;
    bool used;
} E[2008];

llong delta[506], dist[506];
int limit, n, M, k, m = 0, link[2008], head[506], ptr[506];
int heap[506], nheap, pos[506], trace[506];

llong Cost(int i) {
    return E[i].cost + delta[E[i].u] - delta[E[i].v];
}

void UpHeap(int u) {
    if (pos[u] == 0) pos[u] = ++nheap, heap[nheap] = u;

    for(int c = pos[u], p = c >> 1; p > 0; c = p, p >>= 1) {
        if(dist[heap[p]] <= dist[heap[c]]) break;

        swap(pos[heap[p]], pos[heap[c]]);
        swap(heap[p], heap[c]);
    }
}

int Pop_DownHeap() {
    int u = heap[1]; pos[u] = 0;
    heap[1] = heap[nheap--];

    if (nheap == 0) return u;

    pos[heap[1]] = 1;
    for(int p = 1, c = 2; c <= nheap; p = c, c <<= 1) {
        if (c < nheap && dist[heap[c+1]] < dist[heap[c]]) ++c;
        if(dist[heap[p]] <= dist[heap[c]]) break;

        swap(pos[heap[p]], pos[heap[c]]);
        swap(heap[p], heap[c]);
    }

    return u;
}

bool Dijkstra() {
    nheap = 0;
    for(int u=1; u<=n; ++u) dist[u] = 1e18, pos[u] = trace[u] = 0;

    dist[1] = 0; UpHeap(1);
    while (nheap > 0) {
        int u = Pop_DownHeap();

        for(int i = head[u]; i > -1; i = link[i]) {
            int v = E[i].v;

            if (E[i].cap > E[i].flow && dist[v] > dist[u] + Cost(i)) {
                dist[v] = dist[u] + Cost(i);
                trace[v] = u;
                UpHeap(v);
            }
        }
    }

    return dist[n] < 1e18;
}

llong min_cost = 0;

bool DFS(int u) {
    if (u == n) return true;

    for(int &i = ptr[u]; i > -1; i = link[i]) {
        int v = E[i].v, cap = E[i].cap, &flow = E[i].flow;

        if (trace[v] == u && cap - flow >= limit && dist[v] == dist[u] + Cost(i)) {
            bool add = DFS(v);

            if (add) {
                flow += limit;
                E[i^1].flow -= limit;

                min_cost += 1LL * limit * E[i].cost;

                return true;
            }
        }
    }

    return false;
}

void Add_edge(int u, int v, int cap, int cost) {
    E[m] = {u, v, cap, 0, cost, false};
    link[m] = head[u]; head[u] = m++;

    E[m] = {v, u, 0, 0, -cost, false};
    link[m] = head[v]; head[v] = m++;
}

bool visited[506];

void BFS() {
    for(int i = 1; i <= n; ++i) visited[i] = false, trace[i] = -1;
    queue<int> Q; Q.push(1);

    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        if (u == n) return;

        for(int i = head[u]; i > -1; i = link[i]) {
            int v = E[i].v;

            if (!visited[v] && !E[i].used && E[i].cap >= 1 && E[i].cap == E[i].flow) {
                visited[v] = true;
                trace[v] = i;
                Q.push(v);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> M >> k;
    for(int u = 1; u <= n+2; ++u) head[u] = -1;

    for(int i = 1; i <= M; ++i) {
        int u, v; cin >> u >> v;

        ++u, ++v;
        Add_edge(u, v, 1, 1);
    }

    Add_edge(1, 2, k, 0);
    Add_edge(n+1, n+2, k, 0);

    n += 2;

    int max_flow;
    for(limit = 1; limit > 0;) {
        if (!Dijkstra()) {
            limit >>= 1;
            continue;
        }

        for(int u = 1; u <= n; ++u) ptr[u] = head[u];
        while (DFS(1)) max_flow += limit;

        for(int u = 1; u <= n; ++u)
        if (dist[u] < 1e18) delta[u] += dist[u];
    }

    if (max_flow < k) cout << -1;
    else {
        cout << min_cost << '\n';

        for(int i = 1; i <= k; ++i) {
            BFS();

            stack<int> Path;
            int t = n;

            while (t != 1) {
                if (t < n) Path.push(t - 1);

                int i = trace[t];
                if (i == -1) break;

                if (i < m - 4) E[i].used = true;
                t = E[i].u;
            }

            cout << Path.size() << '\n';
            while (!Path.empty()) {
                cout << Path.top() << ' ';
                Path.pop();
            }

            cout << '\n';
        }
    }

    return 0;
}
