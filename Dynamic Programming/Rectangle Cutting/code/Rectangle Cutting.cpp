
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int dp[506][506];
bool visited[506][506];

int DP(int n, int m) {
    if (n == m) return 1;
    if (visited[n][m]) return dp[n][m];

    visited[n][m] = true; dp[n][m] = 1e9;
    for(int i=1; i<n; ++i)
        dp[n][m] = min(dp[n][m], DP(i, m) + DP(n-i, m));

    for(int i=1; i<m; ++i)
        dp[n][m] = min(dp[n][m], DP(n, i) + DP(n, m-i));

    return dp[n][m];
}

int main() {
    int n, m; cin >> n >> m;
    cout << DP(n, m) - 1;

    return 0;
}
