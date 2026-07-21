
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

llong dp[5006][5006], prefix[5006];
int n, opt[5006][5006];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; ++i) {
        int a; cin >> a;
        opt[i][i] = i;
        prefix[i] = prefix[i-1] + a;
    }

    for(int i = n-1; i >= 1; --i)
    for(int j = i+1; j <= n; ++j) {
        dp[i][j] = 1e18;
        opt[i][j] = -1;

        for(int k = opt[i][j-1]; k <= min(opt[i+1][j], j-1); ++k) {
            llong tmp = dp[i][k] + dp[k+1][j] + prefix[j] - prefix[i-1];

            if (tmp < dp[i][j]) {
                dp[i][j] = tmp;
                opt[i][j] = k;
            }
        }
    }

    cout << dp[1][n];

    return 0;
}
