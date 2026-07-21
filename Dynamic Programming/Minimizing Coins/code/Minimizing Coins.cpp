
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int dp[1000006], n, x, c[106];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> x;
    for(int i=1; i<=n; ++i) cin >> c[i];

    dp[0] = 0;
    for(int i=1; i<=x; ++i) {
        dp[i] = 1e9;

        for(int j=1; j<=n; ++j)
        if (i >= c[j]) dp[i] = min(dp[i], dp[i-c[j]] + 1);
    }

    if (dp[x] == 1e9) cout << -1; else cout << dp[x];

    return 0;
}
