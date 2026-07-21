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

int a[200006];

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    for (int i = 30, l = 0; i >= 0; --i) {
        int Max = -1, pos = l;
        for (int j = l; j < n; ++j)
            if ((a[j] & (1 << i)) && a[j] > Max) {
                Max = a[j];
                pos = j;
            }

        if (Max == -1) continue;

        swap(a[pos], a[l]);
        pos = l++;
        for (int j = 0; j < n; ++j)
            if ((a[j] & (1 << i)) && j != pos)
                a[j] ^= Max;
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) ans ^= a[i];
    cout << ans << '\n';
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
