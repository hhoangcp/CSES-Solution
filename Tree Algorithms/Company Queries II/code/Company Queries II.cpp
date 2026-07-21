
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> V[200006];
int n, q, par[200006][20], depth[200006];

void DFS(int u) {
    for(int i = 1; i <= 18; ++i) par[u][i] = par[par[u][i-1]][i-1];

    for(int v: V[u])
    if (par[u][0] != v) {
        par[v][0] = u;
        depth[v] = depth[u] + 1;
        DFS(v);
    }
}

int LCA(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);

    int h = depth[v] - depth[u];
    for(int i = 18; i >= 0; --i)
    if (h & (1 << i)) v = par[v][i];

    if (u == v) return u;

    for(int i = 18; i >= 0; --i)
    if (par[u][i] != par[v][i]) {
        u = par[u][i];
        v = par[v][i];
    }

    return par[u][0];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> q;
    for(int v = 2; v <= n; ++v) {
        int u; cin >> u;
        V[u].push_back(v);
    }

    DFS(1);

    while(q--) {
        int u, v; cin >> u >> v;
        cout << LCA(u, v) << '\n';
    }

    return 0;
}
