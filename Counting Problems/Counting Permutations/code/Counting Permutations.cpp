/// A002464 - OEIS

#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

const llong mod = 1e9+7;
llong dp[100006];
int n;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;
    dp[0] = 1, dp[1] = 1;

    for(int i = 4; i <= n; ++i) {
        dp[i] = ((1LL * i + 1) * dp[i - 1] - (1LL * i - 2) * dp[i - 2] - (1LL * i - 5) * dp[i - 3] + (1LL * i - 3) * dp[i - 4]) % mod;
        (dp[i] += mod) %= mod;
    }

    cout << dp[n];

    return 0;
}
