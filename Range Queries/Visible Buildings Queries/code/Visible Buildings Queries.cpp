#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
#define ull unsigned long long

using namespace std;

struct Data {
    int l, r, id;

    bool operator < (const Data &other) const {
        return l > other.l;
    }
} Q[200006];

int a[100006], ans[200006];

void solve() {
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    for (int i = 1; i <= q; ++i) {
        cin >> Q[i].l >> Q[i].r;
        Q[i].id = i;
    }

    sort(Q + 1, Q + q + 1);

    vector<int> S;
    for (int i = n, curr = 1; i >= 1; --i) {
        while (!S.empty() && a[S.back()] <= a[i]) S.pop_back();
        S.push_back(i);

        while (curr <= q && Q[curr].l == i) {
            int l = i, r = Q[curr].r, id = Q[curr].id;

            int p = lower_bound(S.begin(), S.end(), r, greater<int>()) - S.begin();
            ans[id] = S.size() - p;
            ++curr;
        }
    }

    for (int i = 1; i <= q; ++i) cout << ans[i] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int tests = 1; //cin >> tests;
    for (int i = 0; i < tests; ++i) {
        solve();
    }
}