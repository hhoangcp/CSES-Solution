#include <iostream>
#include <map>
#define ll long long

using namespace std;

int a[200006];

void solve() {
    int n; cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    map<int, int> Left, Pos;

    ll ans = 0;
    for (int i = 1, maxLeft = 0; i <= n; ++i) {
        Left[a[i]] = Pos[a[i]]; Pos[a[i]] = i;
        maxLeft = max(maxLeft, Left[a[i]]);

        ans += i - maxLeft;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int tests = 1; //cin >> tests;
    for (int i = 0; i < tests; ++i) {
        solve();
    }
}