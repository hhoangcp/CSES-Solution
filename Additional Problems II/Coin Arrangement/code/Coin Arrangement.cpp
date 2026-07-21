
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

llong a[100006], b[100006];
int n;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) cin >> b[i];

    llong ans = 0;
    for(int i = 1; i <= n; ++i) {
        if (a[i] < 1 && b[i] > 1) {
            llong delta = min(1-a[i], b[i]-1);
            ans += delta;
            a[i] += delta, b[i] -= delta;
        }

        if (a[i] > 1 && b[i] < 1) {
            llong delta = min(a[i]-1, 1-b[i]);
            ans += delta;
            a[i] -= delta, b[i] += delta;
        }

        ans += abs(a[i] - 1) + abs(b[i] - 1);
        a[i+1] += a[i] - 1;
        b[i+1] += b[i] - 1;
    }

    cout << ans;
    return 0;
}
