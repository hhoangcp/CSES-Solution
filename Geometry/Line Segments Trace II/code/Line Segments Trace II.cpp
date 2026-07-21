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

    line() : a(0), b(-1) {}
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
    if (l > x || r < x) return -1;

    ll ans = liChao[i].calc(x);
    if (l == r) return ans;

    int mid = (l + r) >> 1;
    if (x <= mid) ans = max(ans, query(i * 2 + 1, l, mid, x));
    else ans = max(ans, query(i * 2 + 2, mid + 1, r, x));

    return ans;
}

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int l, u, r, v; cin >> l >> u >> r >> v;

        ll a = (v - u) / (r - l), b = u - l * a;
        line f = line(a, b);
        update(0, 0, m, l, r, f);

    }

    for (int i = 0; i <= m; ++i) cout << query(0, 0, m, i) << " ";
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
