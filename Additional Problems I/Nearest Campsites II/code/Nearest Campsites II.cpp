#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <climits>
#include <array>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <deque>
#include <chrono>
#include <bitset>
#include <iomanip>
#include <stack>
#include <complex>
#include <tuple>
#include <cassert>
#include <random>
#include <functional>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int128 __int128
#define uint128 __uint128_t
#define llong long long
#define ullong unsigned llong
#define int64 long long
#define uint64 uint64_t
#define ll llong
#define ull ullong
#define uint unsigned int
#define sint short int
#define usint unsigned sint
#define eb emplace_back
#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define fst first
#define snd second
#define pii pair<int, int>
#define pli pair<ll, int>
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define tiii tuple<int, int, int>
#define pld pair<ld, ld>
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()

using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

const ll INF = (ll)4e18;

struct BIT {
    int n;
    vector<ll> t;
    BIT(int _n) : n(_n), t(n+1, -INF) {}
    void upd(int i, ll v) {
        for (; i <= n; i += i & -i)
            t[i] = max(t[i], v);
    }
    ll get(int i) {
        ll r = -INF;
        for (; i > 0; i -= i & -i)
            r = max(r, t[i]);
        return r;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<ll> rx(n), ry(n), fx(m), fy(m);
    for (int i = 0; i < n; i++) cin >> rx[i] >> ry[i];
    for (int i = 0; i < m; i++) cin >> fx[i] >> fy[i];

    vector<ll> ans(m, INF);

    for (int it = 0; it < 4; it++) {
        vector<array<ll,4>> v;
        vector<ll> ys;

        auto tr = [&](ll &x, ll &y){
            if (it == 1) y = -y;
            if (it == 2) x = -x;
            if (it == 3) { x = -x; y = -y; }
        };

        for (int i = 0; i < n; i++) {
            ll x = rx[i], y = ry[i];
            tr(x,y);
            v.pub({x, y, 0, -1});
            ys.pub(y);
        }
        for (int i = 0; i < m; i++) {
            ll x = fx[i], y = fy[i];
            tr(x,y);
            v.pub({x,y,1,i});
            ys.pub(y);
        }

        sort(ys.begin(), ys.end());
        ys.erase(unique(ys.begin(), ys.end()), ys.end());

        auto gety = [&](ll y){
            return int(lower_bound(ys.begin(), ys.end(), y) - ys.begin()) + 1;
        };

        sort(v.begin(), v.end(), [](auto &a, auto &b){
            if (a[0] != b[0]) return a[0] < b[0];
            return a[2] < b[2];
        });

        BIT bit(ys.size());

        for (auto &e : v) {
            int yy = gety(e[1]);
            if (e[2] == 0) {
                bit.upd(yy, e[0] + e[1]);
            } else {
                ll best = bit.get(yy);
                if (best != -INF) {
                    ans[e[3]] = min(ans[e[3]],
                        (e[0] + e[1]) - best);
                }
            }
        }
    }

    for (int i = 0; i < m; i++)
        cout << ans[i] << " ";

    cout << '\n';
}

int main() {
    //freopen("test_input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tests = 1;
    for (int i = 0; i < tests; ++i) {
        solve();
    }

    return 0;
}
