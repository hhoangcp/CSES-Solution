
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int mod = 1e9+7;

vector<int> V[100006];
int n, m, dp[100006];
bool visited[100006];

void DFS(int u) {
    visited[u] = 1;
    if (u == n) {
        dp[u] = 1;
        return;
    } else dp[u] = 0;

    for(int v: V[u]) {
        if (!visited[v]) DFS(v);

        (dp[u] += dp[v]) %= mod;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> m;
    while (m--) {
        int u, v; cin >> u >> v;
        V[u].push_back(v);
    }

    DFS(1);
    cout << dp[1];

    return 0;
}
