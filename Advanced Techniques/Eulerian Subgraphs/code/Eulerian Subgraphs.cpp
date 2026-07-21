
#include <iostream>
#include <algorithm>

using namespace std;

const int mod = 1e9+7;
int n, m, Rank[100006], Par[100006];

int Find(int u) {
    if (Par[u] != u) Par[u] = Find(Par[u]);
    return Par[u];
}

bool Union(int u, int v) {
    u = Find(u), v = Find(v);
    if (u == v) return false;

    if (Rank[u] == Rank[v]) ++Rank[u];
    if (Rank[u] > Rank[v]) Par[v] = u; else Par[u] = v;

    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> m;
    for(int u = 1; u <= n; ++u) Par[u] = u;

    int res = 1;
    while (m--) {
        int u, v; cin >> u >> v;
        if (!Union(u, v)) (res *= 2) %= mod;
    }

    cout << res;

    return 0;
}
