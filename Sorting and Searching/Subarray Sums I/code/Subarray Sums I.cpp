
#include <iostream>
#define llong long long

using namespace std;

int a[200006], n;
llong x;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> x;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    llong sum = 0, ans = 0;
    int left = 1;
    for (int right = 1; right <= n; ++right) {
        sum += a[right];
        while (sum > x && left <= right) {
            sum -= a[left];
            ++left;
        }
        if (sum == x) ++ans;
    }

    cout << ans;
    return 0;
}
