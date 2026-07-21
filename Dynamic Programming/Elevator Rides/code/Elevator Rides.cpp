
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

struct Data {
    int r, w;

    bool operator < (const Data &other) const {
        if (r != other.r) return r < other.r;
        return w < other.w;
    }
} dp[(1<<20)+6];

int n, x, w[26];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> x;
    for(int i=0; i<n; ++i) cin >> w[i];

    dp[0] = {1, 0};
    for(int i=1; i < (1 << n); ++i) {
        dp[i] = {n+2, 0};

        for(int j=0; j<n; ++j)
        if(i & (1 << j)) {
            int R = dp[i ^ (1 << j)].r, W = dp[i ^ (1 << j)].w;

            if (W + w[j] > x) {
                ++R;
                W = min(W, w[j]);
            } else W += w[j];

            dp[i] = min(dp[i], {R, W});
        }
    }

    cout << dp[(1<<n) - 1].r;

    return 0;
}
