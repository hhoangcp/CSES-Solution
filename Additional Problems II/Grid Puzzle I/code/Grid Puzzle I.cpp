
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct TEdge {
    int u, v, cap, flow;
} E[7006];

int link[7006], head[106], ptr[106], d[106];
int n, m = 0, limit;

void Add_edge(int u, int v, int cap) {
    E[m] = {u, v, cap, 0};
    link[m] = head[u]; head[u] = m++;

    E[m] = {v, u, 0, 0};
    link[m] = head[v]; head[v] = m++;
}

bool BFS(int s, int t) {
    for(int u = 0; u <= 2*n+1; ++u) d[u] = 1e9;
    queue<int> Q; Q.push(s); d[s] = 0;

    while (!Q.empty()) {
        int u = Q.front(); Q.pop();

        for(int i = head[u]; i > -1; i = link[i]) {
            int v = E[i].v;

            if (d[v] == 1e9 && E[i].cap - E[i].flow >= limit) {
                d[v] = d[u] + 1;
                Q.push(v);
            }
        }
    }

    return d[t] < 1e9;
}

bool DFS(int u, int t) {
    if (u == t) return true;

    for(int &i = ptr[u]; i > -1; i = link[i]) {
        int v = E[i].v, cap = E[i].cap, &flow = E[i].flow;

        if (d[v] == d[u] + 1 && cap - flow >= limit && DFS(v, t)) {
            flow += limit;
            E[i^1].flow -= limit;
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
        Add_edge(0, i, a);
        sum_a += a;
    }

    for(int i = n+1; i <= 2*n; ++i) {
        int b; cin >> b;
        Add_edge(i, 2*n+1, b);
        sum += b;
    }

    for(int u = 1; u <= n; ++u)
    for(int v = n+1; v <= 2*n; ++v) {
        Add_edge(u, v, 1);
        ans[u][v-n] = '.';
    }

    if (sum != sum_a) return cout << -1, 0;

    int max_flow = 0;
    for(limit = 512; limit > 0;) {
        if (!BFS(0, 2*n+1)) {
            limit >>= 1;
            continue;
        }

        for(int u = 0; u <= 2*n+1; ++u) ptr[u] = head[u];

        while (DFS(0, 2*n+1)) max_flow += limit;
    }

    if (max_flow != sum) return cout << -1, 0;

    for(int u = 1; u <= n; ++u)
    for(int i = head[u]; i > -1; i = link[i]) {
        int v = E[i].v;

        if (v > n && v <= 2*n && E[i].cap == 1 && E[i].flow == 1) ans[u][v-n] = 'X';
    }

    for(int u = 1; u <= n; ++u) cout << ans[u] + 1 << '\n';

    return 0;
}
