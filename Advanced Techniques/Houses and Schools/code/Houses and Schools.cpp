
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

llong dp[2][3006];
llong Left[3006][3006], Right[3006][3006];
int a[3006], n, k;

llong Cost(int l, int r) {
    int mid = (l + r) >> 1;
    return Left[l][mid] + Right[mid+1][r];
}

void Init() {
    for(int i = 1; i <= n; ++i)
    for(int j = i; j <= n; ++j)
        Left[i][j] = Left[i][j-1] + (1LL * j - i) * a[j];

    for(int i = 1; i <= n; ++i)
    for(int j = i; j >= 1; --j)
        Right[j][i] = Right[j+1][i] + (1LL * i - j) * a[j];

    for(int i = 1; i <= n; ++i) dp[1][i] = Right[1][i];
}

void DAC(int l, int r, int optl, int optr) {
    if (l > r) return;
    int mid = (l + r) >> 1;

    pair<llong, int> best = {(llong) 1e18, -1};

    for(int i = optl; i <= min(mid, optr); ++i)
    best = min(best, {dp[0][i] + Cost(i, mid), i});

    dp[1][mid] = best.first;
    int opt = best.second;

    DAC(l, mid - 1, optl, opt);
    DAC(mid + 1, r, opt, optr);
}

int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) cin >> a[i];

    Init();

    for(int i = 2; i <= k; ++i) {
        for(int j = 0; j <= n; ++j) dp[0][j] = dp[1][j], dp[1][j] = 0;
        DAC(i, n, i-1, n);
    }

    llong res = 1e18;
    for(int i = k; i <= n; ++i) res = min(res, dp[1][i] + Left[i][n]);

    cout << res;
    return 0;
}
