/// Sum over Subsets DP

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int dp[2][(1<<20)+6];
int n, a[200006], mmax = 0, del = 1, h = 0;

int main() {
    ///freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;
    for(int i=1; i<=n; ++i) {
        cin >> a[i];
        mmax = max(mmax, a[i]);
    }

    while (del <= mmax) ++h, del <<= 1;
    --del;

    for(int i=1; i<=n; ++i) ++dp[1][a[i]], ++dp[0][a[i]];

    for(int i=0; i<h; ++i) {
        for(int j=0; j<=del; ++j)
        if (j & (1 << i)) dp[1][j] += dp[1][j ^ (1 << i)];

        for(int j=del; j>0; --j)
        if ((j & (1 << i)) == 0) dp[0][j] += dp[0][j | (1 << i)];
    }

    for(int i=1; i<=n; ++i) cout << dp[1][a[i]] << ' ' << dp[0][a[i]] << ' ' << n - dp[1][del ^ a[i]] << '\n';

    return 0;
}
