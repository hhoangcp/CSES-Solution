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

const int MOD = 1e9 + 7;

int add(int a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}

void solve() {
    int n, a;
    cin >> n >> a;

    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];

    vector<int> b(n);
    for (int i = 0; i < n; i++) b[i] = x[i] - a;

    const int OFFSET = 250000;
    const int MAXS = OFFSET * 2;

    vector<int> dp(MAXS + 1, 0);
    dp[OFFSET] = 1;

    for (int i = 0; i < n; i++) {
        if (b[i] >= 0) {
            for (int s = MAXS - b[i]; s >= 0; s--)
                if (dp[s])
                    dp[s + b[i]] = add(dp[s + b[i]], dp[s]);
        } else {
            for (int s = -b[i]; s <= MAXS; s++)
                if (dp[s])
                    dp[s + b[i]] = add(dp[s + b[i]], dp[s]);
        }
    }

    int ans = dp[OFFSET] - 1;
    if (ans < 0) ans += MOD;

    cout << ans << '\n';
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
