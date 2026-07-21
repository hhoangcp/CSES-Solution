
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define llong long long

using namespace std;

struct TEdge {
    int u, v, c, f;
    bool used;
} E[4006];

int limit, link[4006], head[506], ptr[506], d[506], n, m;
int trace[506];

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

void Tracing() {
    for(int u = 1; u <= n; ++u) d[u] = -1, trace[u] = -1;
    d[1] = 0; queue<int> Q; Q.push(1);

    while (!Q.empty()) {
        int u = Q.front(); Q.pop();

        for(int i = head[u]; i > -1; i = link[i]) {
            int v = E[i].v, c = E[i].c, f = E[i].f;

            if (d[v] == -1 && c == 1 && c == f && !E[i].used) {
                d[v] = d[u] + 1;
                trace[v] = i;
                Q.push(v);
            }
        }
    }

    vector<int> Path;
    int v = n;
    while (v != 0) {
        Path.push_back(v);

        int i = trace[v];
        if (i == -1) break;
        E[i].used = true;

        v = E[i].u;
    }

    reverse(Path.begin(), Path.end());

    cout << Path.size() << '\n';
    for(int u: Path) cout << u << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> m;
    for(int u = 1; u <= n; ++u) head[u] = -1;

    for(int i = 0; i < 2 * m; i += 2) {
        int u, v; cin >> u >> v;

        E[i] = {u, v, 1, 0, false};
        E[i+1] = {v, u, 0, 0, false};

        link[i] = head[u]; head[u] = i;
        link[i+1] = head[v]; head[v] = i+1;
    }

    int max_flow = 0;
    for(limit = 1; limit > 0; ) {
        if (!BFS()) {
            limit >>= 1;
            continue;
        }

        for(int u = 1; u <= n; ++u) ptr[u] = head[u];

        while (DFS(1)) max_flow += limit;
    }

    cout << max_flow << '\n';
    for(int i = 1; i <= max_flow; ++i) Tracing();

    return 0;
}
