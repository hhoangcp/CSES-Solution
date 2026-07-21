
#include <iostream>
#include <algorithm>
#include <bitset>

using namespace std;

int par[100006], sz[100006], n, m;
int num[100006];

int Find(int u) {
    if (par[u] != u) return par[u] = Find(par[u]);
    return u;
}

void Union(int u, int v) {
    u = Find(u), v = Find(v);
    if (u == v) return;

    if (sz[u] < sz[v]) swap(u, v);
    par[v] = u, sz[u] += sz[v];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> m;

    for(int u = 1; u <= n; ++u) par[u] = u, sz[u] = 1;
    for(int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        Union(u, v);
    }

    bitset<100001> knapsack; knapsack[0] = 1;

    for(int u = 1; u <= n; ++u)
    if (Find(u) == u) ++num[sz[u]];

    for(int i = 1; i <= n; ++i)
    if (num[i] > 0) {
        ++num[i];

        int delta = (1 << (31 - __builtin_clz(num[i])));
        for(int j = 1; j < delta; j <<= 1) knapsack |= knapsack << (j * i);

        if (delta < num[i]) knapsack |= knapsack << ((num[i] - delta) * i);
    }

    for(int i = 1; i <= n; ++i) cout << knapsack[i];

    return 0;
}
