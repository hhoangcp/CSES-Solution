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

int a[1006], inv[1006];

void solve() {
    int n; cin >> n;
    if (n == 1) {
        cout << "1 1" << endl;
        int tmp; cin >> tmp;
        assert(tmp == 0);
        return;
    }

    inv[1] = 0;
    for (int i = 2; i <= n; ++i) {
        cout << 1 << ' ' << i << endl;
        int pre; cin >> pre;
        if (pre == 0) return;

        cout << 1 << ' ' << i << endl;
        int cur; cin >> cur;
        if (cur == 0) return;

        inv[i] = (cur - pre + i * (i - 1) / 2) / 2;
    }

    for (int val = 1; val <= n; ++val) {
        int cnt = 0, pos = -1;

        for (int i = 1; i <= n; ++i) {
            if (a[i] > 0) ++cnt;
            else {
                if (inv[i] - inv[i - 1] + cnt == i - 1) pos = i;
            }
        }

        assert(pos != -1);

        a[pos] = val;
    }

    for (int i = 1; i <= n; ++i) {
        int pos = i;
        for (int j = i + 1; j <= n; ++j)
            if (a[pos] > a[j]) pos = j;

        if (i < pos) {
            cout << i << ' ' << pos << endl;
            int l = i, r = pos;
            while (l < r) swap(a[l++], a[r--]);

            int tmp; cin >> tmp;
            if (tmp == 0) return;
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
