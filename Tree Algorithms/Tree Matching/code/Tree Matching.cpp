
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> V[200006];
int n, lab[200006], dp[200006][2];

void DFS(int u) {
    dp[u][0] = dp[u][1] = 0;

    for(int v: V[u])
    if (lab[u] != v) {
        lab[v] = u;
        DFS(v);
        dp[u][0] += max(dp[v][0], dp[v][1]);
    }

    vector<int> Left(V[u].size(), 0);
    for(int i = 0; i < (int) V[u].size(); ++i) {
        int v = V[u][i];
        if (lab[u] != v) {
            Left[i] = max(dp[v][0], dp[v][1]);
            if (i > 0) Left[i] += Left[i-1];
        } else if (i > 0) Left[i] = Left[i-1];
    }

    int Right = 0;
    for(int i = V[u].size()-1; i >= 0; --i) {
        int v = V[u][i];
        if (lab[u] != v) {
            if (i > 0) dp[u][1] = max(dp[u][1], 1 + dp[v][0] + Right + Left[i-1]);
            else dp[u][1] = max(dp[u][1], 1 + dp[v][0] + Right);

            Right += max(dp[v][0], dp[v][1]);
        }
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
    cout << max(dp[1][0], dp[1][1]);

    return 0;
}
