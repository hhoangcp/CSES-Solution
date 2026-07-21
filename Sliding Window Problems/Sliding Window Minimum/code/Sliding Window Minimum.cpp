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

int x[10000007];

void solve() {
    int n, k; cin >> n >> k;
    int a, b, c; cin >> x[1] >> a >> b >> c;
    for (int i = 2; i <= n; ++i) x[i] = (1LL * a * x[i - 1] + b) % c;

    deque<int> dq;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        while (!dq.empty() && x[dq.back()] >= x[i]) dq.pob();
        while (!dq.empty() && dq.front() <= i - k) dq.pof();
        dq.push_back(i);

        if (i >= k) ans ^= x[dq.front()];
    }

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
