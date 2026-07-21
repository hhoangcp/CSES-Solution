
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

const llong mod = 1e9+7;
llong fact[200006], inv_f[200006], res[200006], dp[2][200006];
int n, k;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> k; k = min(1LL * k, 1LL * n * (n - 1) / 2 - k);
    if (k < 0) return cout << 0, 0;

    fact[0] = fact[1] = inv_f[0] = inv_f[1] = 1;
    for(int i = 2; i <= n+k; ++i) {
        fact[i] = fact[i-1] * i % mod;
        inv_f[i] = mod - (mod / i) * inv_f[mod % i] % mod;
    }

    for(int i = 2; i <= n+k; ++i) (inv_f[i] *= inv_f[i-1]) %= mod;

    dp[0][0] = 1;
    int B = (int)sqrt(2.0 * k) + 5;
    for(int i = 0; i <= B; ++i) {
        for(int j = 0; j <= k; ++j) dp[1][j] = 0;
        for(int j = 0; j <= k; ++j)
        if (dp[0][j]) {
            if (i + j + 1 <= k) ((dp[1][i+j+1] -= dp[0][j]) += mod) %= mod;
            if (i > 0 && i + j <= k) (dp[0][i+j] += dp[0][j]) %= mod;
        }

        for(int j = 0; j <= k; ++j) {
            (res[j] += dp[0][j]) %= mod;
            dp[0][j] = dp[1][j];
        }
    }

    for(int i = 0; i <= k; ++i) dp[0][i] = res[i], res[i] = 0;

    for(int i = 0; i * n <= k; ++i) {
        for(int j = 0; j <= k; ++j) dp[1][j] = 0;

        for(int j = 0; j <= k; ++j)
        if (dp[0][j]) {
            if (i > 0 && i + j <= k) (dp[0][i + j] += dp[0][j]) %= mod;
            if (j + n + 1 <= k) (dp[1][j + n + 1] += dp[0][j]) %= mod;
        }

        for(int j = 0; j <= k; ++j) {
            (res[j] += dp[0][j]) %= mod;
            dp[0][j] = dp[1][j];
        }
    }

    llong ans = 0;
    for(int i = 0; i <= k; ++i) {
        llong delta = fact[k-i+n-1] * (inv_f[n-1] * inv_f[k-i] % mod) % mod;
        (delta *= res[i]) %= mod;
        (ans += delta) %= mod;
    }

    cout << ans;

    return 0;
}
