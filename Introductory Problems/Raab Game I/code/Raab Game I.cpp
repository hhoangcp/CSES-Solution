#include <iostream>

using namespace std;

int A[100006], B[100006];

void solve() {
    int n, a, b; cin >> n >> a >> b;
    if ((a == 0 && b != 0) || (a != 0 && b == 0) || (a + b > n)) {
        cout << "NO\n";
        return;
    }

    int draw = n - a - b;
    for (int i = 1; i <= draw; ++i) A[i] = B[i] = i;

    int curr = draw;
    for (int i = 0; i < a; ++i, ++curr) A[curr + 1] = n - a + 1 + i, B[curr + 1] = draw + 1 + i;

    for (int i = 0; i < b; ++i, ++curr) B[curr + 1] = n - b + 1 + i, A[curr + 1] = draw + 1 + i;

    cout << "YES\n";
    for (int i = 1; i <= n; ++i) cout << A[i] << " ";
    cout << '\n';
    for (int i = 1; i <= n; ++i) cout << B[i] << " ";
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int tests = 1; cin >> tests;
    for (int i = 0; i < tests; ++i) {
        solve();
    }
}