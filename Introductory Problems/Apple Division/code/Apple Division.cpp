
#include <cstdio>
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

int n, a[26];
llong res = 1e18, sum[2];

void Try(int p) {
    if (res == 0) return;
    if (p > n) res = min(res, abs(sum[0] - sum[1]));
    else
        for(int i=0; i<=1; ++i) {
            sum[i] += a[p];
            Try(p+1);
            sum[i] -= a[p];
        }
}

int main() {
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];

    Try(1);
    cout << res;

    return 0;
}
