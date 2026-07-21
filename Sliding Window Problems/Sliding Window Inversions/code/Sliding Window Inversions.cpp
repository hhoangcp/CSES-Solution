#include <algorithm>
#include <iostream>
#include <cmath>
#include <deque>
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

int a[200006], bit[200006], sorted[200006], sz = 0;

void update(int p, int val) {
    for (; p <= sz; p += p & -p) bit[p] += val;
}

int query(int p) {
    int ans = 0;
    for (; p > 0; p -= p & -p) ans += bit[p];
    return ans;
}

void solve() {
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sorted[++sz] = a[i];
    }

    sort(sorted + 1, sorted + sz + 1);
    sz = unique(sorted + 1, sorted + sz + 1) - sorted - 1;

    ll tot = 0;
    for (int i = 1; i <= n; ++i) {
        a[i] = lower_bound(sorted + 1, sorted + sz + 1, a[i]) - sorted;
        tot += min(i - 1, k) - query(a[i]); update(a[i], 1);

        if (i > k) {
            tot -= query(a[i - k] - 1);
            update(a[i - k], -1);
        }

        if (i >= k) cout << tot << ' ';
    }

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
