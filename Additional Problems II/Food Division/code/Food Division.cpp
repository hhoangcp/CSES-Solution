
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

llong a[200006];
int n;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];

    llong sum = 0;
    for(int i = 1; i <= n; ++i) {
        int b; cin >> b;
        a[i] += a[i-1] - b;
        sum += a[i];
    }

    llong ans = 0;
    sort(a+1, a+n+1);

    for(int i = 1; i <= n; ++i) ans += abs(a[i] - a[(n+1) / 2]);

    cout << ans;

    return 0;
}
