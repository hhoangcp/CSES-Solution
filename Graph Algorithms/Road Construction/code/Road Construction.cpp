
#include <iostream>
#include <algorithm>

using namespace std;

int par[100006], n, m, sz[1000006];

int Find(int u) {
    if (par[u] != u) par[u] = Find(par[u]);
    return par[u];
}

int cur_max = 1, components;

bool Union(int u, int v) {
    u = Find(u), v = Find(v);
    if (u == v) return false;

    if (sz[u] < sz[v]) swap(u, v);
    sz[u] += sz[v];
    cur_max = max(cur_max, sz[u]);
    par[v] = u;

    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> m; components = n;
    for(int u = 1; u <= n; ++u) par[u] = u, sz[u] = 1;

    for(int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;

        if (Union(u, v)) --components;
        cout << components << ' ' << cur_max << '\n';
    }

    return 0;
}
