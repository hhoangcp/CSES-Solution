#pragma GCC optimize("Ofast,unroll-loops,inline,omit-frame-pointer,fast-math,no-stack-protector")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt,fma")
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

ll ans[26];
char a[506][506];
int colS[506];

void solve() {
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) cin >> a[i][j];

    for (int u = 0; u < n; ++u) {
        for (int i = 0; i < n; ++i) colS[i] = 0;

        for (int v = u; v < n; ++v) {
            for (int i = 0; i < n; ++i) {
                if (colS[i] == -1) continue;
                if (u == v) {
                    colS[i] = a[v][i] - 'A';
                } else if (colS[i] != a[v][i] - 'A') colS[i] = -1;
            }

            int cur = -1, num = 0;
            for (int i = 0; i < n; ++i) {
                if (a[u][i] != a[v][i] || a[u][i] - 'A' != cur) {
                    cur = (a[u][i] == a[v][i]) ? a[u][i] - 'A' : -1;
                    num = 0;
                }

                if (colS[i] == a[u][i] - 'A') ans[colS[i]] += ++num;
            }

        }
    }

    for (int i = 0; i < k; ++i) cout << ans[i] << '\n';
}

int main() {
    //freopen("test_input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tests = 1;
    for (int i = 0; i < tests; ++i) {
        solve();
    }

    return 0;
}
