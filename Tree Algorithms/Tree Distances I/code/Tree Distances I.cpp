
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> V[200006];
int n, lab[200006], dp[200006], ans[200006];

void DFS(int u) {
    dp[u] = 0;

    for(int v: V[u])
    if (lab[u] != v) {
        lab[v] = u;

        DFS(v);
        dp[u] = max(dp[u], dp[v] + 1);
    }
}

void Rotate(int u) {
    ans[u] = dp[u];
    vector<int> Left(V[u].size(), 0);

    for(int i = 0; i < (int) V[u].size(); ++i) {
        int v = V[u][i];
        Left[i] = dp[v] + 1;
        if (i > 0) Left[i] = max(Left[i], Left[i-1]);
    }

    int Right = 0;
    for(int i = V[u].size() - 1; i >= 0; --i) {
        int v = V[u][i];

        if (lab[u] != v) {
            int tmp_u = dp[u], tmp_v = dp[v];
            if (i > 0) dp[u] = max(Left[i-1], Right); else dp[u] = Right;
            dp[v] = max(dp[v], dp[u] + 1);

            Rotate(v);
            dp[u] = tmp_u, dp[v] = tmp_v;
        }

        Right = max(Right, dp[v] + 1);
    }
}

int main() {
    ///freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;
    for(int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        V[u].push_back(v);
        V[v].push_back(u);
    }

    DFS(1);
    Rotate(1);
    for(int i = 1; i <= n; ++i) cout << ans[i] << ' ';

    return 0;
}
