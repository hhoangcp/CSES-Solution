#include <iostream>

using namespace std;

int a[1006][1006];

void solve() {
    int n; cin >> n;

    if (n <= 3) {
        cout << "IMPOSSIBLE" << '\n';
        return;
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) a[i][j] = i;
    }

    for (int i = 1; i <= n; ++i) a[i][n] = n;
    for (int i = 1; i <= n; ++i) a[n][i] = i;

    if (n % 2) swap(a[n][2], a[n / 2][n]);
    else {
        swap(a[n][n - 1], a[n / 2 - 1][n]);
        swap(a[n][n / 2 - 1], a[n / 2][n / 2 - 1]);
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) cout << a[i][j] << ' ';
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tests = 1;
    for (int i = 0; i < tests; ++i) {
        solve();
    }
}
