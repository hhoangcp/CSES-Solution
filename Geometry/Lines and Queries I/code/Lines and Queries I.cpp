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

line liChao[200006];

void update(int l, int r, line f) {
    if (l > r) return;
    int mid = (l + r) >> 1;
    if (l == r) {
        liChao[mid] = (liChao[mid].calc(l) < f.calc(l)) ? f : liChao[mid];
        return;
    }

    if (f.calc(mid) > liChao[mid].calc(mid)) swap(f, liChao[mid]);

    if (f.slope() < liChao[mid].slope())
        update(l, mid, f);

    if (f.slope() > liChao[mid].slope())
        update(mid + 1, r, f);
}

ll query(int l, int r, int x) {
    if (l > x || r < x) return 0;

    int mid = (l + r) >> 1;
    ll ans = liChao[mid].calc(x);
    if (l == r) return ans;

    if (x <= mid) ans = max(ans, query(l, mid, x));
    else ans = max(ans, query(mid + 1, r, x));

    return ans;
}

void solve() {
    int n; cin >> n; int m = 100'000;
    while (n--) {
        int kind; cin >> kind;
        if (kind == 1) {
            int a, b; cin >> a >> b;
            update(0, m, line(a, b));
        } else {
            int x; cin >> x;
            cout << query(0, m, x) << '\n';
        }
    }
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