#include <algorithm>
#include <cassert>
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

int cnt = 0;

pii cal(int i, int k) {
    if (i <= 0) {
        ++cnt;
        cout << "S " << k - i << endl;
        int s; cin >> s;
        return pii(s, LLONG_MAX);
    }

    if (k - i <= 0) {
        ++cnt;
        cout << "F " << i << endl;
        int f; cin >> f;
        return pii(f, LLONG_MIN);
    }

    cout << "F " << i << endl;
    int f; cin >> f;
    ++cnt;

    cout << "S " << k - i << endl;
    int s; cin >> s;
    ++cnt;

    return pii(min(f, s), f - s);
}

void solve() {
    int n, k; cin >> n >> k;

    int l = max(0, k - n), r = min(k, n);
    while (l < r) {
        int mid = (l + r) >> 1;
        if (cal(mid, k).snd <= 0) {
            r = mid;
        } else l = mid + 1;
    }

    int ans = cal(l, k).fst;
    if (l > 0 && k - l < n) ans = max(ans, cal(l - 1, k).fst);

    assert(cnt <= 100);

    cout << "! " << ans << endl;
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
