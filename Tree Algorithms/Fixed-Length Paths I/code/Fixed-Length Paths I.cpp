
#include <iostream>
#include <algorithm>
#include <vector>
#define llong long long

using namespace std;

llong ans = 0;
vector<int> V[200006];
int n, k, subtree_sz[200006], cnt[200006], max_depth = 0;
bool cnode[200006];

int DFS_sz(int u, int par) {
    subtree_sz[u] = 1;
    for(int v: V[u])
    if (v != par && !cnode[v]) subtree_sz[u] += DFS_sz(v, u);

    return subtree_sz[u];
}

int Find_Centroid(int sz, int u, int par) {
    for(int v: V[u])
    if (v != par && !cnode[v] && subtree_sz[v] * 2 > sz) return Find_Centroid(sz, v, u);

    return u;
}

void Get_cnt(int u, int par, bool add, int depth = 1) {
    if (depth > k) return;
    max_depth = max(max_depth, depth);

    if (add) ++cnt[depth];
    else ans += cnt[k - depth];

    for(int v: V[u])
    if (v != par && !cnode[v]) Get_cnt(v, u, add, depth+1);
}

void Centroid_Decomposition(int u = 1) {
    int centroid = Find_Centroid(DFS_sz(u, 0), u, 0);
    cnode[centroid] = true;

    max_depth = 0;
    for(int v: V[centroid])
    if (!cnode[v]) {
        Get_cnt(v, centroid, false);
        Get_cnt(v, centroid, true);
    }

    while (max_depth > 0) cnt[max_depth--] = 0;
    for(int v: V[centroid])
    if (!cnode[v]) Centroid_Decomposition(v);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> k;
    for(int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        V[u].push_back(v);
        V[v].push_back(u);
    }

    cnt[0] = 1;
    Centroid_Decomposition();
    cout << ans;

    return 0;
}
