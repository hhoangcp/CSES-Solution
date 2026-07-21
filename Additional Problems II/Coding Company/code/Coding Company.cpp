
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

const llong mod = 1e9+7;
llong dp[2][56][10006];
int n, x, a[106];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> x;
    for(int i = 1; i <= n; ++i) cin >> a[i];

    sort(a+1, a+n+1);

    dp[0][0][5000] = 1;
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= 50; ++j)
        for(int k = 0; k <= 10000; ++k) {
            (dp[1][j][k] += (1LL * j + 1) * dp[0][j][k]) %= mod;
            if (j - 1 >= 0 && k + a[i] <= 10000) (dp[1][j][k] += dp[0][j - 1][k + a[i]]) %= mod;
            if (j + 1 <= 50 && k - a[i] >= 0) (dp[1][j][k] += (1LL * j + 1) * dp[0][j + 1][k - a[i]]) %= mod;
        }

        for(int j = 0; j <= 50; ++j)
        for(int k = 0; k <= 10000; ++k) dp[0][j][k] = dp[1][j][k], dp[1][j][k] = 0;
    }

    llong ans = 0;
    for(int i = 0; i <= x; ++i) (ans += dp[0][0][5000 + i]) %= mod;

    cout << ans;

    return 0;
}
