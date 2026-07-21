
#include <iostream>
#include <algorithm>
#include <vector>
#define llong long long

using namespace std;

vector<int> V[100006], Vs[100006], S;
llong W[100006], dp[100006];
int n, m, lab[100006], Sconnect = 0;
int low[100006], num[100006], w[100006];
bool tick[100006];

void DFS(int u) {
    low[u] = 1e9, num[u] = ++num[0];
    S.push_back(u);

    for(int v: V[u])
    if (!tick[v]) {
        if (num[v] > 0) low[u] = min(low[u], num[v]);
        else {
            DFS(v);
            low[u] = min(low[u], low[v]);
        }
    }

    if (low[u] >= num[u]) {
        ++Sconnect;

        do {
            int v = S.back(); S.pop_back();
            lab[v] = Sconnect;
            tick[v] = true;
            W[Sconnect] += w[v];
            if (v == u) break;
        } while (!S.empty());
    }
}

void DFS2(int u) {
    if (tick[u]) return;
    tick[u] = true;
    dp[u] = W[u];

    for(int v: Vs[u]) {
        DFS2(v);
        dp[u] = max(dp[u], dp[v] + W[u]);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> w[i];

    for(int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        V[u].push_back(v);
    }

    for(int u = 1; u <= n; ++u)
    if (!tick[u]) DFS(u);

    llong res = 0;
    for(int u = 1; u <= n; ++u)
    for(int v: V[u])
    if (lab[u] != lab[v]) Vs[lab[u]].push_back(lab[v]);

    for(int u = 1; u <= Sconnect; ++u) tick[u] = 0;
    for(int u = 1; u <= Sconnect; ++u)
    if (!tick[u]) {
        DFS2(u);
        res = max(res, dp[u]);
    }

    cout << res;

    return 0;
}
