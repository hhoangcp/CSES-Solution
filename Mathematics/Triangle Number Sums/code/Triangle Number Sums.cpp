#include <algorithm>
#include <iostream>
#include <cmath>
#define ll long long
#define ull unsigned long long

using namespace std;

// https://proofwiki.org/wiki/Integer_is_Sum_of_Three_Triangular_Numbers

void solve() {
   ll n; cin >> n;

    ll sum = 0;
    for (int i = 0; sum <= n; ++i, sum += i) {
        ll sum2 = n - sum;

        int p = sqrt(2 * sum2);
        if (i > p) break;
        if (1LL * p * (p + 1) == 2 * sum2) {
            cout << 2 - (sum == 0) - (sum2 == 0) << '\n';
            return;
        }
    }

    cout << 3 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tests = 1; cin >> tests;
    for (int i = 0; i < tests; ++i) {
        solve();
    }
}
