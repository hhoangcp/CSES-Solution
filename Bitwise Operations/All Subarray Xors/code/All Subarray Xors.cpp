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

const int H = 20;
const int MAX = 1 << H;

ll numX[MAX];
int pre[200006];

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        pre[i] = pre[i - 1] ^ x;
    }

    for (int i = 0; i <= n; ++i) ++numX[pre[i]];

    /// XOR
    for (int len = (MAX >> 1); len > 0; len >>= 1)
        for (int i = 0; i < MAX; i += (len << 1))
            for (int j = 0; j < len; ++j) {
                const ll u = numX[i + j];
                const ll v = numX[i + j + len];
                numX[i + j] = u + v;
                numX[i + j + len] = u - v;
            }

    for (ll &val : numX)
        val *= val;

    for (int len = 1; len < MAX; len <<= 1)
        for (int i = 0; i < MAX; i += (len << 1))
            for (int j = 0; j < len; ++j) {
                const ll u = numX[i + j];
                const ll v = numX[i + j + len];
                numX[i + j] = u + v;
                numX[i + j + len] = u - v;
            }

    vector<int> ans;
    for (int mask = 0; mask < MAX; ++mask) {
        numX[mask] >>= H;

        if (mask == 0) numX[mask] -= n;
        numX[mask] >>= 1;

        if (numX[mask] > 0) ans.push_back(mask);
    }

    cout << ans.size() << '\n';
    for (int v: ans) cout << v << ' ';
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
