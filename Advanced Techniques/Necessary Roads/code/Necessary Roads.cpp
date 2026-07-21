
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct TEdge {
    int u, v, id;
};

int n, m;
vector<TEdge> V[100006];
int cnt = 0, low[100006], num[100006], nChild[100006];
int lab[100006];
bool cut[100006], nedge[400006];

void DFS(int u) {
    low[u] = 1e9, num[u] = ++num[0];

    for(TEdge v: V[u])
    if (!nedge[v.id]) {
        nedge[v.id ^ 1] = true;

        if (lab[v.v] == 0) {
            lab[v.v] = u;
            DFS(v.v);
            low[u] = min(low[u], low[v.v]);
        } else low[u] = min(low[u], num[v.v]);
    }
}

void Get_bridges() {
    vector<TEdge> Bridges;

    for(int v=1; v<=n; ++v) {
        int u = lab[v];
        if (u == -1) continue;

        if (low[v] >= num[v]) Bridges.push_back({u, v});
    }

    cout << Bridges.size() << '\n';
    for(TEdge e: Bridges) cout << e.u << ' ' << e.v << '\n';
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < 2 * m; i += 2) {
        int u, v; cin >> u >> v;

        V[u].push_back({u, v, i});
        V[v].push_back({v, u, i^1});
    }

    for(int u=1; u<=n; ++u)
    if (lab[u] == 0) {
        lab[u] = -1;
        DFS(u);
    }

    Get_bridges();

    return 0;
}
