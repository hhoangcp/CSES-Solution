#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#define ll long long
#define ull unsigned long long

using namespace std;

int a[100006], p[100006];
char ans[100006];

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        p[a[i]] = i;
    }

    int cnt = 0;
    for (int i = 1; i < n; ++i)
        if (p[a[i] + 1] > p[a[i + 1] + 1]) ++cnt;

    if (cnt >= 26) {
        cout << "-1\n";
        return;
    }

    cnt = 0; ans[a[1]] = 'a';
    for (int i = 1; i < n; ++i) {
        if (p[a[i] + 1] > p[a[i + 1] + 1]) ++cnt;
        ans[a[i + 1]] = cnt + 'a';
    }

    cout << ans + 1;
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tests = 1; //cin >> tests;
    for (int i = 0; i < tests; ++i) {
        solve();
    }
}
