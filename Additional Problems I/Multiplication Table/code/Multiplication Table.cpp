
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

int n;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;
    llong p = (1LL * n * n + 1) >> 1;

    llong l = 1, r = 1LL * n * n, ans = -1;
    while (l <= r) {
        llong mid = (l + r) >> 1;

        llong Leq = 0;
        for(int i = 1; i <= n; ++i)
            Leq += min(1LL * n, mid / i);

        if (Leq >= p) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }

    cout << ans;

    return 0;
}
