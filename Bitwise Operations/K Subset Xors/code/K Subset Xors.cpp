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

int basis[31], sz = 0;

void insertVector(int mask) {
    for (int i = 29; i >= 0; --i) {
        if (~mask & (1 << i)) continue;

        if (!basis[i]) {
            basis[i] = mask;
            ++sz;
            return;
        }

        mask ^= basis[i];
    }
}

int query(int k) {
    int mask = 0;
    int tot = 1 << sz;
    for (int i = 29; i >= 0; --i)
        if (basis[i]) {
            int mid = tot / 2;
            if (mid < k && ~mask & 1 << i) {
                mask ^= basis[i];
            } else if (mid >= k && mask & 1 << i) {
                mask ^= basis[i];
            }

            if (mid < k) k -= mid;

            tot >>= 1;
        }

    return mask;
}

void solve() {
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        int a; cin >> a;
        insertVector(a);
    }

    if (sz >= n) {
        for (int i = 1; i <= k; ++i) cout << query(i) << ' ';
    } else {
        if (n - sz >= 20) {
            for (int i = 1; i <= k; ++i) cout << 0 << ' ';
        } else {
            int len = 1 << (n - sz);
            for (int i = 1; i <= k; ++i)
                cout << query((i - 1) / len + 1) << ' ';
        }
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
