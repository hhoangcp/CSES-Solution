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
#define int128 __int128_t
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

int x[200006], y[200006];

string to_string(int128 A) {
    if (A == 0) return "0";
    
    string ans = "";
    bool neg = A < 0;
    if (neg) A = -A;

    while (A != 0) {
        ans.push_back('0' + A % 10);
        A = A / 10;
    }

    reverse(ans.begin(), ans.end());
    if (neg)
        ans = "-" + ans;

    return ans;
}

void solve() {
    int n; cin >> n;

    for (int i = 1; i <= n; ++i) cin >> x[i] >> y[i];

    sort(x + 1, x + n + 1);
    sort(y + 1, y + n + 1);

    int128 ans = 0, sumX = 0, sumY = 0;
    for (int i = 1; i <= n; ++i) {
        ans += 1LL * (x[i] + y[i]) * (i - 1) - sumX - sumY;
        sumX += x[i];
        sumY += y[i];
    }

    string Ans = to_string(ans);
    cout << Ans << '\n';
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
