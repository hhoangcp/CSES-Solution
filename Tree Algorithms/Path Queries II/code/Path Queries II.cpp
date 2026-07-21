#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> V[200006];
int n, q, w[200006], Seg[400006];
int depth[200006], sz[200006], chain[200006], lab[200006], pos[200006];

void Update(int u, int val) {
    u += n; Seg[u] = val;
    for(u >>= 1; u > 0; u >>= 1) Seg[u] = max(Seg[u<<1], Seg[(u<<1)|1]);
}

int Query(int l, int r) {
    int mmax = 0;
    for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if ((l & 1) == 1) mmax = max(mmax, Seg[l++]);
        if ((r & 1) == 0) mmax = max(mmax, Seg[r--]);
    }

    if (l == r) mmax = max(mmax, Seg[l]);
    return mmax;
}

void DFS(int u) {
    int p = -1; sz[u] = 1;

    for(int i = 0; i < (int) V[u].size(); ++i) {
        int v = V[u][i];
        if (lab[u] == v) continue;

        lab[v] = u; depth[v] = depth[u] + 1;
        DFS(v);
        sz[u] += sz[v];

        if (p == -1 || sz[V[u][p]] < sz[v]) p = i;
    }

    if (p != -1) swap(V[u][0], V[u][p]);
}

void HLD(int u, int c) {
    chain[u] = c; pos[u] = ++pos[0];

    if (V[u].empty()) return;
    if (lab[u] != V[u][0]) HLD(V[u][0], c);

    for(int i = 1; i < (int) V[u].size(); ++i) {
        int v = V[u][i];
        if (lab[u] != v) HLD(v, v);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> q;
    for(int i = 1; i <= n; ++i) cin >> w[i];
    for(int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        V[u].push_back(v);
        V[v].push_back(u);
    }

    DFS(1);
    HLD(1, 1);
    for(int u = 1; u <= n; ++u) Update(pos[u], w[u]);

    while (q--) {
        int type; cin >> type;

        if (type == 1) {
            int u, x; cin >> u >> x;
            Update(pos[u], x);
        } else {
            int u, v; cin >> u >> v;

            int mmax = 0;
            while (chain[u] != chain[v]) {
                if (depth[chain[u]] > depth[chain[v]]) swap(u, v);
                mmax = max(mmax, Query(pos[chain[v]], pos[v]));
                v = lab[chain[v]];
            }

            if (depth[u] > depth[v]) swap(u, v);
            mmax = max(mmax, Query(pos[u], pos[v]));

            cout << mmax << ' ';
        }
    }

    return 0;
}
