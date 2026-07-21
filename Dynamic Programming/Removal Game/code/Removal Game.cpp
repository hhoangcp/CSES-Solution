
#include <cstdio>
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

llong dp[5006], pre[5006];
int n, a[5006];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];

    for(int i=n; i>=1; --i) {
        int first_player = n & 1;

        for(int j=i; j<=n; ++j) {
            pre[j] = dp[j];

            if (first_player) dp[j] = max(dp[j-1] + a[j], pre[j] + a[i]);
            else dp[j] = min(dp[j-1], pre[j]);

            first_player ^= 1;
        }
    }

    cout << dp[n];

    return 0;
}
