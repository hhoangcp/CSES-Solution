#include <algorithm>
#include <iostream>

using namespace std;

int f[200006], prime[20006], sz = 0;

void sieve(int n = 200000) {
    for (int i = 1; i <= n; ++i) f[i] = 0;
    sz = 0;

    for (int i = 2; i <= n; ++i) {
        if (f[i] == 0) f[i] = prime[++sz] = i;
        for (int j = 1; j <= sz && prime[j] <= f[i] && prime[j] * i <= n; ++j)
            f[prime[j] * i] = prime[j];
    }
}

int b[100006];

void solve(int n) {
    if (n <= 0) return;
    int p = upper_bound(prime + 1, prime + sz + 1, n) - prime;
    int m = prime[p] - n;
    for (int i = m; i <= n; ++i) b[i] = prime[p] - i;
    solve(m - 1);
}

void solve() {
    int n; cin >> n;
    sieve(2 * n);

    solve(n);

    for (int i = 1; i <= n; ++i) cout << i << ' ';
    cout << '\n';
    for (int i = 1; i <= n; ++i) cout << b[i] << ' ';
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
