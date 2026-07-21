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

struct Edge {
    int u, v;
} E[306];

int dp[1 << 16], trace[1 << 16], color[16];
bool valid[1 << 16];

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v; --u, --v;
        E[i] = {u, v};
    }

    for (int mask = 0; mask < (1 << n); ++mask) {
        valid[mask] = true;
        for (int i = 1; i <= m && valid[mask]; ++i) {
            int u = E[i].u, v = E[i].v;
            if (mask & (1 << u) && mask & (1 << v)) valid[mask] = false;
        }
    }

    dp[0] = 0;
    for (int mask = 1; mask < (1 << n); ++mask) dp[mask] = INT_MAX;

    for (int mask = 0; mask < (1 << n); ++mask)
        for (int submask = mask; submask > 0; submask = (submask - 1) & mask) {
            if (!valid[submask]) continue;
            if (dp[mask] > dp[mask ^ submask] + 1) {
                dp[mask] = dp[mask ^ submask] + 1;
                trace[mask] = submask;
            }
        }

    int tot = 0;
    for (int mask = (1 << n) - 1; mask > 0; ++tot) {
        int submask = trace[mask];

        for (int i = 0; i < n; ++i)
            if (submask & (1 << i)) color[i] = tot;

        mask ^= submask;
    }

    cout << tot << '\n';
    for (int i = 0; i < n; ++i) cout << color[i] + 1 << ' ';
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