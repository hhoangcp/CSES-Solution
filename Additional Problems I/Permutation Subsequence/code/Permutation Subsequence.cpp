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

struct Fenwick {
    int n;
    vector<pii> bit;

    Fenwick(int n): n(n), bit(n+1, {0, -1}) {}

    void update(int i, pii v) {
        for (; i <= n; i += i & -i)
            bit[i] = max(bit[i], v);
    }

    pii query(int i) {
        pii res = {0, -1};
        for (; i > 0; i -= i & -i)
            res = max(res, bit[i]);
        return res;
    }
};

void solve() {
    int n, m; cin >> n >> m;

    vi a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    unordered_map<int, int> pos;
    pos.reserve(m * 2);
    for (int i = 0; i < m; i++) pos[b[i]] = i + 1;

    vector<int> c;
    vector<int> idx;
    for (int i = 0; i < n; i++) {
        if (pos.count(a[i])) {
            c.pub(pos[a[i]]);
            idx.pub(i);
        }
    }

    int k = c.size();
    Fenwick fw(m);
    vi dp(k), pre(k, -1);

    for (int i = 0; i < k; i++) {
        auto best = fw.query(c[i] - 1);
        dp[i] = best.fst + 1;
        pre[i] = best.snd;
        fw.update(c[i], {dp[i], i});
    }

    int best = 0, at = -1;
    for (int i = 0; i < k; i++) {
        if (dp[i] > best) {
            best = dp[i];
            at = i;
        }
    }

    vector<int> ans;
    while (at != -1) {
        ans.pub(a[idx[at]]);
        at = pre[at];
    }
    reverse(ans.begin(), ans.end());

    cout << ans.size() << "\n";
    for (int x : ans) cout << x << " ";
    cout << "\n";
}

int main() {
    //freopen("test_input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tests = 1; //cin >> tests;
    for (int i = 0; i < tests; ++i) {
        solve();
    }

    return 0;
}
