/// Dominator Tree

#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>

using namespace std;

vector<int> V[100006], V_rev[100006], Tree[100006], Bucket[100006];
int n, m, sdom[100006], par[100006], lab[100006], dom[100006], dsu[100006];
int num[100006], pos[100006];

int Find(int u, int x = 0) {
    if (u == dsu[u]) return x ? -1 : u;

    int v = Find(dsu[u], x+1);
    if (v < 0) return u;

    if (sdom[lab[dsu[u]]] < sdom[lab[u]])
        lab[u] = lab[dsu[u]];

    dsu[u] = v;
    return x ? v : lab[u];
}

void Union(int u, int v) {
    dsu[v] = u;
}

void DFS(int u) {
    num[u] = ++num[0]; pos[num[0]] = u;
    lab[num[0]] = num[0], sdom[num[0]] = num[0], dsu[num[0]] = num[0];

    for(int i = 0; i < (int) V[u].size(); ++i) {
        int v = V[u][i];

        if (!num[v]) {
            DFS(v);
            par[num[v]] = num[u];
        }

        V_rev[num[v]].push_back(num[u]);
    }
}

bool tick[100006];
int trace[100006];

void DFS2(int u) {
    tick[u] = true;

    for(int v: Tree[u])
    if (!tick[v]) {
        trace[v] = u;
        DFS2(v);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        V[u].push_back(v);
    }

    DFS(1);
    int t = n, N = n;

    n = num[0];
    for(int u = n; u >= 1; --u) {
        for(int v: V_rev[u]) sdom[u] = min(sdom[u], sdom[Find(v)]);

        if (u > 1) Bucket[sdom[u]].push_back(u);

        for(int v: Bucket[u]) {
            int w = Find(v);
            if (sdom[w] == sdom[v]) dom[v] = sdom[v];
            else dom[v] = w;
        }

        if (u > 1) Union(par[u], u);
    }

    for(int u = 2; u <= n; ++u) {
        if (dom[u] != sdom[u]) dom[u] = dom[dom[u]];
        Tree[pos[u]].push_back(pos[dom[u]]);
        Tree[pos[dom[u]]].push_back(pos[u]);
    }

    DFS2(1);
    for(int i = 1; i <= N; ++i) tick[i] = false;

    int ans = 1; tick[1] = true;
    while (t != 1) {
        ++ans;
        tick[t] = true;
        t = trace[t];
    }

    cout << ans << '\n';
    for(int u = 1; u <= N; ++u)
    if (tick[u]) cout << u << ' ';

    return 0;
}
