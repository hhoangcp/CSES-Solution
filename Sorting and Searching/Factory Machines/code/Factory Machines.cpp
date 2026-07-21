
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

int n, t;
int a[200006];

bool check(llong Time) {
    llong delta = 0;
    for(int i = 0; i < n; ++i) {
        delta += Time / a[i];
        if (delta >= t) return true;
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> t;
    for(int i = 0; i < n; ++i) cin >> a[i];

    llong l = 0, r = 1e18, ans = 1e18;
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
