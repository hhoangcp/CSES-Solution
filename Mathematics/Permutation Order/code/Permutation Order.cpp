#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#define ll long long
#define ull unsigned long long

using namespace std;

ll fact[26];

void task1(int n, ll k) {
    vector<int> a(n); --k;
    vector<bool> used(n);

    for (int i = 0; i < n; ++i) {
        int p = k / fact[n - i - 1];
        k -= p * fact[n - i - 1];
        for (int j = 0; j < n && p >= 0; ++j)
            if (!used[j]) {
                if (p == 0) {
                    a[i] = j;
                    used[j] = true;
                    break;
                } else --p;
            }
    }

    for (int i = 0; i < n; ++i) cout << a[i] + 1 << " ";
    cout << '\n';
}

void task2(int n, vector<int> a) {
    vector<bool> used(n);
    ll ans = 0;

    for (int i = 0; i < n; ++i) {
        int curr = 0;

        for (int j = 0; j < n; ++j) {
            if (j == a[i] - 1) break;
            if (!used[j]) ++curr;
        }

        ans += curr * fact[n - i - 1];
        used[a[i] - 1] = true;
    }

    cout << ans + 1 << '\n';
}

void solve() {
    int t, n; cin >> t >> n;

    if (t == 1) {
        ll k; cin >> k;
        task1(n, k);
    } else {
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        task2(n, a);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    fact[0] = 1;
    for (int i = 1; i <= 20; ++i) fact[i] = fact[i - 1] * i;

    int tests = 1; cin >> tests;
    for (int i = 0; i < tests; ++i) {
        solve();
    }
}