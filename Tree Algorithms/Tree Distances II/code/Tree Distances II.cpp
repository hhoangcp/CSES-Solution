
#include <iostream>
#include <algorithm>
#include <vector>
#define llong long long

using namespace std;

llong dp[200006], ans[200006];
vector<int> V[200006];
int n, sz[200006], lab[200006];

void DFS(int u) {
    dp[u] = 0, sz[u] = 1;

    for(int v: V[u])
    if (lab[u] != v) {
        lab[v] = u;

        DFS(v);
        dp[u] += dp[v] + sz[v];
        sz[u] += sz[v];
    }
}

void Rotate(int u) {
    ans[u] = dp[u];

    for(int v: V[u])
    if (lab[u] != v) {
        dp[u] -= dp[v] + sz[v];
        sz[u] -= sz[v];
        sz[v] += sz[u];
        dp[v] += dp[u] + sz[u];

        Rotate(v);

        sz[v] -= sz[u];
        dp[v] -= dp[u] + sz[u];
        dp[u] += dp[v] + sz[v];
        sz[u] += sz[v];
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;
    for(int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        V[u].push_back(v);
        V[v].push_back(u);
    }

    DFS(1);
    Rotate(1);

    for(int u = 1; u <= n; ++u) cout << ans[u] << ' ';

    return 0;
}
