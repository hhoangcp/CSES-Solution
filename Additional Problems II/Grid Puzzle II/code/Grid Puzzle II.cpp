
#include <iostream>
#include <algorithm>
#include <deque>
#define llong long long

using namespace std;

struct TEdge {
    int u, v, cap, flow, cost;
} E[7006];

llong dist[106];
int link[7006], color[106], head[106], ptr[106], trace[106];
int n, m = 0, limit;

void Add_edge(int u, int v, int cap, int cost) {
    E[m] = {u, v, cap, 0, cost};
    link[m] = head[u]; head[u] = m++;

    E[m] = {v, u, 0, 0, -cost};
    link[m] = head[v]; head[v] = m++;
}

/// D'Esopo-Pape
bool Shortest_Path(int s, int t) {
    for(int u = 0; u <= 2*n+1; ++u) dist[u] = 2e18, trace[u] = -1, color[u] = 0;
    deque<int> DQ; DQ.push_back(s); dist[s] = 0;

    while (!DQ.empty()) {
        int u = DQ.front(); DQ.pop_front();
        color[u] = 2;

        for(int i = head[u]; i > -1; i = link[i]) {
            int v = E[i].v;

            if (dist[v] > dist[u] + E[i].cost && E[i].cap - E[i].flow >= limit) {
                dist[v] = dist[u] + E[i].cost;
                trace[v] = u;

                if (color[v] == 0) {
                    color[v] = 1;
                    DQ.push_back(v);
                } else if (color[v] == 2) {
                    color[v] = 1;
                    DQ.push_front(v);
                }
            }
        }
    }

    return dist[t] < 2e18;
}

llong min_cost = 0;

bool DFS(int u, int t) {
    if (u == t) return true;

    for(int &i = ptr[u]; i > -1; i = link[i]) {
        int v = E[i].v, cap = E[i].cap, &flow = E[i].flow, cost = E[i].cost;

        if (trace[v] == u && dist[v] == dist[u] + E[i].cost && cap - flow >= limit && DFS(v, t)) {
            flow += limit;
            E[i^1].flow -= limit;
            min_cost += 1LL * limit * cost;

            return true;
        }
    }

    return false;
}

char ans[56][56];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;
    int sum_a = 0, sum = 0;
    fill(head, head+2*n+2, -1);

    for(int i = 1; i <= n; ++i) {
        int a; cin >> a;
        Add_edge(0, i, a, 0);
        sum_a += a;
    }

    for(int i = n+1; i <= 2*n; ++i) {
        int b; cin >> b;
        Add_edge(i, 2*n+1, b, 0);
        sum += b;
    }

    for(int u = 1; u <= n; ++u)
    for(int v = n+1; v <= 2*n; ++v) {
        int cost; cin >> cost;

        Add_edge(u, v, 1, -cost);
        ans[u][v-n] = '.';
    }

    if (sum != sum_a) return cout << -1, 0;

    int max_flow = 0;
    for(limit = 512; limit > 0;) {
        if (!Shortest_Path(0, 2*n+1)) {
            limit >>= 1;
            continue;
        }

        for(int u = 0; u <= 2*n+1; ++u) ptr[u] = head[u];

        while (DFS(0, 2*n+1)) max_flow += limit;
    }

    if (max_flow != sum) return cout << -1, 0;

    cout << -min_cost << '\n';
    for(int u = 1; u <= n; ++u)
    for(int i = head[u]; i > -1; i = link[i]) {
        int v = E[i].v;

        if (v > n && v <= 2*n && E[i].cap == 1 && E[i].flow == 1) ans[u][v-n] = 'X';
    }

    for(int u = 1; u <= n; ++u) cout << ans[u] + 1 << '\n';

    return 0;
}
