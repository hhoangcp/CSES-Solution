
#pragma GCC target("popcnt")
#include <iostream>
#include <algorithm>
#include <vector>
#define llong long long

using namespace std;

vector<int> V[50006];
llong dp[50006][786];
int n, m, block;
bool visited[50006];

void DFS(int u) {
    if (visited[u]) return;
    visited[u] = true;
    dp[u][u >> 6] |= (1LL << (u % 64));

    for(int v: V[u]) {
        DFS(v);

        for(int i = 0; i < block; ++i)
            dp[u][i] |= dp[v][i];
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> m; block = (n + 63) >> 6;
    for(int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v; --u, --v;
        V[u].push_back(v);
    }

    for(int u = 0; u < n; ++u)
    if (!visited[u]) DFS(u);

    for(int u = 0; u < n; ++u) {
        int cnt = 0;

        for(int i = 0; i < block; ++i)
            cnt += __builtin_popcountll(dp[u][i]);

        cout << cnt << ' ';
    }

    return 0;
}
