
#include <iostream>
#include <algorithm>
#include <vector>
#define llong long long

using namespace std;

vector<int> V[50006], Vs[50006], S;
llong dp[50006][786];
int low[50006], num[50006], n, m, q, lab[50006], block, Sc = 0;
bool tick[50006], visited[50006];

void Tarjan(int u) {
    low[u] = 1e9, num[u] = ++num[0];
    S.push_back(u);

    for(int v: V[u])
    if (!tick[v]) {
        if (num[v] > 0) low[u] = min(low[u], num[v]);
        else {
            Tarjan(v);
            low[u] = min(low[u], low[v]);
        }
    }

    if (low[u] >= num[u]) {
        do {
            int v = S.back(); S.pop_back();
            lab[v] = Sc; tick[v] = true;
            if (v == u) break;
        } while (!S.empty());

        ++Sc;
    }
}

void DFS(int u) {
    if (visited[u]) return;
    visited[u] = true;
    dp[u][u >> 6] |= (1LL << (u % 64));

    for(int v: Vs[u]) {
        DFS(v);

        for(int i = 0; i < block; ++i)
            dp[u][i] |= dp[v][i];
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> m >> q;
    for(int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        V[u].push_back(v);
    }

    for(int u = 1; u <= n; ++u)
    if (!tick[u]) Tarjan(u);

    for(int u = 1; u <= n; ++u)
    for(int v: V[u])
    if (lab[u] != lab[v]) Vs[lab[u]].push_back(lab[v]);

    for(int u = 0; u < Sc; ++u) {
        sort(Vs[u].begin(), Vs[u].end());
        Vs[u].resize(unique(Vs[u].begin(), Vs[u].end()) - Vs[u].begin());
    }

    block = (Sc + 63) >> 6;
    for(int u = 0; u < Sc; ++u)
    if (!visited[u]) DFS(u);

    while (q--) {
        int u, v; cin >> u >> v;
        u = lab[u], v = lab[v];

        if (dp[u][v >> 6] & (1LL << (v % 64))) cout << "YES\n"; else cout << "NO\n";
    }

    return 0;
}
