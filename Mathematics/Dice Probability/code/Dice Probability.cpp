
#include <iostream>
#include <algorithm>
#define ldouble long double

using namespace std;

ldouble dp[106][606];
int n, a, b;

int main() {
    cin >> n >> a >> b;

    dp[0][0] = 1.0L;
    for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= 6*i; ++j)
    for(int k = 1; k <= 6; ++k)
    if (j - k >= 0) dp[i][j] += dp[i-1][j-k] * (1.0L / 6.0L);

    ldouble ans = 0;
    for(int i = a; i <= b; ++i) ans += dp[n][i];

    (cout << fixed).precision(6);
    cout << ans;

    return 0;
}
