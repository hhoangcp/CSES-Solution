
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define llong long long

using namespace std;

struct TEdge {
    int u, v, c, f;
} E[10006];

int limit, link[10006], head[506], ptr[506], d[506], n, m;

bool BFS() {
    for(int u = 1; u <= n; ++u) d[u] = -1;
    d[1] = 0; queue<int> Q; Q.push(1);

    while (!Q.empty()) {
        int u = Q.front(); Q.pop();

        for(int i = head[u]; i > -1; i = link[i]) {
            int v = E[i].v, c = E[i].c, f = E[i].f;

            if (d[v] == -1 && c - f >= limit) {
                d[v] = d[u] + 1;
                Q.push(v);
            }
        }
    }

    while (!Q.empty()) Q.pop();
    return d[n] != -1;
}

bool DFS(int u) {
    if (u == n) return true;

    for(int &i = ptr[u]; i > -1; i = link[i]) {
        int v = E[i].v, c = E[i].c, f = E[i].f;

        if (d[v] == d[u] + 1 && c - f >= limit) {
            bool add = DFS(v);

            if (add) {
                E[i].f += limit;
                E[i^1].f -= limit;
                return true;
            }
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> m;
    for(int u = 1; u <= n; ++u) head[u] = -1;

    for(int i = 0; i < 2 * m; i += 2) {
        int u, v, c; cin >> u >> v >> c;

        E[i] = {u, v, c, 0};
        E[i+1] = {v, u, 0, 0};

        link[i] = head[u]; head[u] = i;
        link[i+1] = head[v]; head[v] = i+1;
    }

    llong max_flow = 0;
    for(limit = (1 << 30); limit > 0; ) {
        if (!BFS()) {
            limit >>= 1;
            continue;
        }

        for(int u = 1; u <= n; ++u) ptr[u] = head[u];

        while (DFS(1)) max_flow += limit;
    }

    cout << max_flow;

    return 0;
}
