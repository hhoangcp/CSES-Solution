
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

bool checking(llong x, llong pivot) {
    llong num = 0;

    for(llong h = 1; h <= x; h *= 10) {
        llong d = h * 10;

        num += x / d * h + min(max(x % d - h + 1, 0LL), h);
    }

    return num <= pivot;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    llong n; cin >> n;
    if (n <= 0) return cout << 0, 0;

    llong l = 10, r = 9e17, ans = 9;
    while (l <= r) {
        llong mid = (l + r) >> 1;
        if (checking(mid, n)) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }

    cout << ans;

    return 0;
}
