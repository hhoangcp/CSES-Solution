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

struct Point {
    int x, y;
} P[200006];

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> P[i].x >> P[i].y;

    ll max_diff = LLONG_MIN, min_diff = LLONG_MAX;
    ll max_sum = LLONG_MIN, min_sum = LLONG_MAX;
    for (int i = 1; i <= n; ++i) {
        ll diff = P[i].x - P[i].y;
        min_diff = min(min_diff, diff);
        max_diff = max(max_diff, diff);

        ll sum = P[i].x + P[i].y;
        min_sum = min(min_sum, sum);
        max_sum = max(max_sum, sum);

        cout << max(max_diff - min_diff, max_sum - min_sum) << '\n';
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
