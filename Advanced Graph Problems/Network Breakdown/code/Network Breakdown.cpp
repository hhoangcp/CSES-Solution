
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

set<pair<int, int> > Start;
vector<pair<int, int> > Q;
int par[100006], sz[100006];
int comps, n, m, k, ans[200006];

int Find(int u) {
    if (par[u] != u) par[u] = Find(par[u]);
    return par[u];
}

void Union(int u, int v) {
    u = Find(u), v = Find(v);
    if (u == v) return;

    --comps;
    if (sz[u] < sz[v]) swap(u, v);
    par[v] = u, sz[u] += sz[v];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> m >> k;
    for(int u = 1; u <= n; ++u) par[u] = u, sz[u] = 1;

    for(int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        if (u > v) swap(u, v);
        Start.insert({u, v});
    }

    for(int i = 0; i < k; ++i) {
        int u, v; cin >> u >> v;
        if (u > v) swap(u, v);

        Start.erase(Start.find({u, v}));
        Q.push_back({u, v});
    }

    comps = n;
    for(pair<int, int> edge: Start) Union(edge.first, edge.second);

    for(int i = k - 1; i >= 0; --i) {
        ans[i+1] = comps;
        Union(Q[i].first, Q[i].second);
    }

    for(int i = 1; i <= k; ++i) cout << ans[i] << ' ';

    return 0;
}
