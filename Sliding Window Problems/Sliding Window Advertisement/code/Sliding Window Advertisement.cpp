#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <tuple>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <bitset>
#include <iomanip>
#include <sstream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int128 __int128
#define uint128 __uint128_t
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int, int>
#define pil pair<int, ll>
#define pli pair<ll, int>
#define pll pair<ll, ll>
#define fst first
#define snd second
#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define mp make_pair
#define mt make_tuple

using namespace std;

struct line {
    ll a, b;

    line() : a(0), b(LLONG_MIN) {}
    line(ll a, ll b) : a(a), b(b) {}

    ll calc(ll x) { return a * x + b; }
    ll slope() { return a; }
};

line liChao[800006];

void insertLine(int i, int l, int r, line f) {
    if (l > r) return;
    if (l == r) {
        liChao[i] = (liChao[i].calc(l) < f.calc(l)) ? f : liChao[i];
        return;
    }

    int mid = (l + r) >> 1;
    if (f.calc(mid) > liChao[i].calc(mid)) swap(f, liChao[i]);

    if (f.slope() < liChao[i].slope())
        insertLine(i * 2 + 1, l, mid, f);

    if (f.slope() > liChao[i].slope())
        insertLine(i * 2 + 2, mid + 1, r, f);
}

void update(int i, int l, int r, int u, int v, line f) {
    if (l > v || r < u) return;
    if (u <= l && r <= v)
        return insertLine(i, l, r, f), void();

    int mid = (l + r) >> 1;
    update(i * 2 + 1, l, mid, u, v, f);
    update(i * 2 + 2, mid + 1, r, u, v, f);
}

ll query(int i, int l, int r, int x) {
    if (l > x || r < x) return LLONG_MIN;

    ll ans = liChao[i].calc(x);
    if (l == r) return ans;

    int mid = (l + r) >> 1;
    if (x <= mid) ans = max(ans, query(i * 2 + 1, l, mid, x));
    else ans = max(ans, query(i * 2 + 2, mid + 1, r, x));

    return ans;
}

int L[200006], R[200006], a[200006];

void solve() {
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    stack<int> S;
    for (int i = 1; i <= n; ++i) {
        while (!S.empty() && a[S.top()] >= a[i]) S.pop();
        if (S.empty()) L[i] = 1;
        else L[i] = S.top() + 1;
        S.push(i);
    }

    while (!S.empty()) S.pop();
    for (int i = n; i >= 1; --i) {
        while (!S.empty() && a[S.top()] >= a[i]) S.pop();
        if (S.empty()) R[i] = n;
        else R[i] = S.top() - 1;
        S.push(i);
    }

    for (int i = 1; i <= n; ++i) {
        int l = L[i], r = R[i], len = r - l + 1;

        if (len < k) {
            line f = line(a[i], -1LL * (l - 1) * a[i]);
            update(0, 1, n, l, r, f);

            if (r + 1 <= min(n, l + k - 1))
                update(0, 1, n, r + 1, min(n, l + k - 1), line(0, 1LL * len * a[i]));

            f = line(-a[i], 1LL * (l + k - 1 + len) * a[i]);
            if (l + k <= min(n, l + k + len - 2))
                update(0, 1, n, l + k, min(n, l + k + len - 2), f);
        } else {
            line f = line(a[i], -1LL * (l - 1) * a[i]);
            update(0, 1, n, l, l + k - 1, f);

            if (l + k <= r)
                update(0, 1, n, l + k, r, line(0, 1LL * a[i] * k));

            f = line(-a[i], 1LL * (r + k) * a[i]);
            if (r + 1 <= min(n, r + k - 1)) update(0, 1, n, r + 1, min(n, r + k - 1), f);
        }
    }

    for (int i = k; i <= n; ++i) cout << query(0, 1, n, i) << " ";
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
