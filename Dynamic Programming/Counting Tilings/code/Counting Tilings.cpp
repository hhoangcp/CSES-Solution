/// DP on Broken Profile

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int mod = 1e9+7;
int dp[(1<<10)+6][2], n, m;

int main() {
    cin >> n >> m;

    dp[0][0] = 1;
    for(int j=1; j<=m; ++j)
    for(int i=1; i<=n; ++i) {
        for(int state = 0; state < (1 << n); ++state) {
            dp[state][1] = dp[state ^ (1 << (i-1))][0];
            if (i > 1 && (state & (1 << (i-1))) == 0 && (state & (1 << (i-2))) == 0)
                dp[state][1] = (dp[state][1] + dp[state ^ (1 << (i-2))][0]) % mod;
        }

        for(int state = 0; state < (1 << n); ++state) dp[state][0] = dp[state][1];
    }

    cout << dp[0][0];

    return 0;
}
