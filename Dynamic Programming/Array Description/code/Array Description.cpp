#include <iostream>
#include <algorithm>

using namespace std;

const int mod = 1e9+7;
int n, m, dp[2][106];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> m;
    for(int i=1; i<=n; ++i) {
        int a; cin >> a;

        if (i == 1) {
            if (a == 0) for(int j=1; j<=m; ++j) dp[1][j] = 1;
            else dp[1][a] = 1;
        } else {
            for(int j=1; j<=m; ++j) dp[0][j] = dp[1][j], dp[1][j] = 0;

            if (a == 0) {
                for(int j=1; j<=m; ++j)
                for(int k=max(1, j-1); k<=min(m, j+1); ++k) dp[1][j] = (dp[1][j] + dp[0][k]) % mod;
            } else for(int j=max(1, a-1); j<=min(m, a+1); ++j) dp[1][a] = (dp[1][a] + dp[0][j]) % mod;
        }
    }

    int res = 0;
    for(int i=1; i<=m; ++i) res = (res + dp[1][i]) % mod;

    cout << res;

    return 0;
}
