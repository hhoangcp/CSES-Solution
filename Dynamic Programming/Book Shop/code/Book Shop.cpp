
#include <cstdio>
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

llong dp[100006];
int n, x, h[1006];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> x;
    for(int i=1; i<=n; ++i) cin >> h[i];

    llong res = 0;
    for(int i=1; i<=n; ++i) {
        int s; cin >> s;

        for(int j=x; j>=h[i]; --j) {
            dp[j] = max(dp[j], dp[j-h[i]] + s);
            res = max(res, dp[j]);
        }
    }

    cout << res;

    return 0;
}
