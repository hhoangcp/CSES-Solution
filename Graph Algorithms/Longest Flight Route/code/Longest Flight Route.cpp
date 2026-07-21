
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> V[100006];
int n, m, dp[100006], trace[100006];
bool visited[100006];

void DFS(int u) {
    visited[u] = 1;
    if (u == n) {
        dp[u] = 1;
        return;
    } else dp[u] = -1e9;

    for(int v: V[u]) {
        if (!visited[v]) DFS(v);

        if (dp[u] < dp[v] + 1) {
            dp[u] = dp[v] + 1;
            trace[u] = v;
        }
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
    if (dp[1] <= 0) cout << "IMPOSSIBLE";
    else {
        cout << dp[1] << '\n';

        int t = 1;
        while (t != n) {
            cout << t << ' ';
            t = trace[t];
        }

        cout << t;
    }

    return 0;
}
