
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int mod = 1e9+7;
int dp[1000006], n, x, c[106];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> x;
    for(int i=1; i<=n; ++i) cin >> c[i];

    dp[0] = 1;
    for(int j=1; j<=n; ++j)
    for(int i=1; i<=x; ++i)
    if (i >= c[j]) dp[i] = (dp[i] + dp[i-c[j]]) % mod;

    cout << dp[x];

    return 0;
}
