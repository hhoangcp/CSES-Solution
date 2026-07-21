
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

const int mod = 1e9+7;
llong dp[1006][1006];
int n, k;

int Squares(int p) {
    if (p & 1) return p / 4 * 2 + 1;
    return (p - 1) / 4 * 2 + 2;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> k;
    if (k >= 2*n) {
        cout << '0';
        return 0;
    }

    for(int i = 0; i < 2*n; ++i) dp[i][0] = 1;
    dp[1][1] = 1;

    for(int i = 2; i < 2*n; ++i)
    for(int j = 1; j <= k; ++j)
        dp[i][j] = ((dp[i-2][j] + dp[i-2][j-1] * (Squares(i) - j + 1)) % mod + mod) % mod;

    llong ans = 0;
    for(int i = 0; i <= k; ++i)
        (ans += dp[2*n-1][i] * dp[2*n-2][k-i]) %= mod;

    cout << ans;

    return 0;
}
