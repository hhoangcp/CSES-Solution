
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int mod = 1e9+7;
int dp[1006][1006], n;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;
    for(int i=1; i<=n; ++i)
    for(int j=1; j<=n; ++j) {
        char c; cin >> c;

        if (i == 1 && j == 1) dp[i][j] = (int) (c == '.');
        else if (c == '.') dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod;
        else dp[i][j] = 0;
    }

    cout << dp[n][n];

    return 0;
}
