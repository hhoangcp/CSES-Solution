#include <algorithm>
#include <iostream>
#define ll long long
#define ull unsigned long long

using namespace std;

bool is_prime(ll n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;
    if (n % 3 == 0) return false;

    for (int i = 5, add = 2; 1LL * i * i <= n; i += add, add = 6 - add) {
        if (n % i == 0) return false;
    }

    return true;
}

void solve() {
    ll n; cin >> n;
    while (++n) {
        if (is_prime(n)) break;
    }

    cout << n << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int tests = 1; cin >> tests;
    for (int i = 0; i < tests; ++i) {
        solve();
    }
}