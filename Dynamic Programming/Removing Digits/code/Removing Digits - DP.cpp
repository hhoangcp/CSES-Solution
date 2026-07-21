
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int dp[1000006], n;

int main() {
    cin >> n;

    for (int u = 1; u <= n; ++u) dp[u] = 1e9;
    dp[0] = 0;

    for (int u = 1; u <= n; ++u) {
        int tmp = u;
        while (tmp > 0) {
            int d = tmp % 10;
            if (d != 0) dp[u] = min(dp[u], dp[u - d] + 1);
            tmp /= 10;
        }
    }

    cout << dp[n];

    return 0;
}
