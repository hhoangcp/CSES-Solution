
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

struct TEdge {
    int u, v, cap, flow, cost;
} E[88006];

llong delta[408], dist[408];
int limit, n, m = 0, link[88006], head[408], ptr[408], trace[408];
bool visited[408];

llong Cost(int i) {
    return E[i].cost + delta[E[i].u] - delta[E[i].v];
}

bool Dijkstra() {
    for(int u = 1; u <= n; ++u) dist[u] = 1e18, trace[u] = 0, visited[u] = false;
    trace[1] = 0, dist[1] = 0;

    do {
        int u = 0;
        for(int v = 1; v <= n; ++v)
        if (!visited[v] && (u == 0 || dist[v] < dist[u]))
            u = v;

        if (u == 0) break;
        visited[u] = true;

        for(int i = head[u]; i > -1; i = link[i]) {
            int v = E[i].v, cap = E[i].cap, flow = E[i].flow;

            if (!visited[v] && cap - flow >= limit && dist[v] > dist[u] + Cost(i)) {
                dist[v] = dist[u] + Cost(i);
                trace[v] = u;
            }
        }

    } while (true);

    return trace[n] != 0;
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
    E[m] = {u, v, cap, 0, cost};
    link[m] = head[u]; head[u] = m++;

    E[m] = {v, u, 0, 0, -cost};
    link[m] = head[v]; head[v] = m++;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;
    for(int u = 1; u <= 2*n+2; ++u) head[u] = -1;

    for(int i = 2; i <= n+1; ++i)
    for(int j = 2; j <= n+1; ++j) {
        int c; cin >> c;
        Add_edge(i, j+n, 1, c);
    }

    for(int i = 2; i <= n+1; ++i) {
        Add_edge(1, i, 1, 0);
        Add_edge(i+n, 2*n+2, 1, 0);
    }

    n *= 2, n += 2;

    for(limit = 1; limit > 0;) {
        if (!Dijkstra()) {
            limit >>= 1;
            continue;
        }

        for(int u = 1; u <= n; ++u) ptr[u] = head[u];
        while (DFS(1));

        for(int u = 1; u <= n; ++u)
        if (dist[u] < 1e18) delta[u] += dist[u];
    }

    cout << min_cost << '\n';
    for(int u = 2; (u << 1) <= n; ++u)
    for(int i = head[u]; i > -1; i = link[i])
        if (E[i].cap == 1 && E[i].flow == 1) {
            cout << u - 1 << ' ' << E[i].v - (n >> 1) << '\n';
            break;
        }

    return 0;
}
