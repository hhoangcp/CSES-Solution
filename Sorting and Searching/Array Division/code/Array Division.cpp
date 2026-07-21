
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

int n, a[200006], k, mmax = 0;

bool check(llong sum) {
    llong cur = 0;
    int num = 0;

    for(int i = 1; i <= n; ++i) {
        cur += a[i];
        if (cur > sum) cur = a[i], ++num;
    }

    if (cur > 0) ++num;
    return num <= k;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> k;
    llong sum = 0;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        mmax = max(mmax, a[i]);
        sum += a[i];
    }

    llong l = mmax, r = sum, ans = 0;
    while (l <= r) {
        llong mid = (l + r) >> 1;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }

    cout << ans;

    return 0;
}
