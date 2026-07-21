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

int lg2[501];
int st[9][501][9][501];
char a[501][501];

void solve() {
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
            st[0][i][0][j] |= 1 << (a[i][j] - 'A');
        }

    for (int i = 2; i <= n; ++i) lg2[i] = lg2[i >> 1] + 1;

    for (int i = 1; i <= n; ++i)
        for (int l = 1; (1 << l) <= n; ++l)
            for (int j = 1; j + (1 << l) - 1 <= n; ++j)
                st[0][i][l][j] = st[0][i][l - 1][j] | st[0][i][l - 1][j + (1 << (l - 1))];

    for (int t = 1; (1 << t) <= n; ++t)
        for (int i = 1; i + (1 << t) - 1 <= n; ++i)
            for (int l = 0; (1 << l) <= n; ++l)
                for (int j = 1; j + (1 << l) - 1 <= n; ++j)
                    st[t][i][l][j] = st[t - 1][i][l][j] | st[t - 1][i + (1 << (t - 1))][l][j];

    int full = (1 << k) - 1;
    auto check = [&] (int x, int y, int u, int v) -> bool {
        int lx = lg2[u - x + 1];
        int ly = lg2[v - y + 1];

        int a = st[lx][x][ly][y] | st[lx][u - (1 << lx) + 1][ly][y];
        int b = st[lx][x][ly][v - (1 << ly) + 1] | st[lx][u - (1 << lx) + 1][ly][v - (1 << ly) + 1];

        return (a | b) == full;
    };

    ll ans = 0;
    for (int l = 1; l <= n; ++l)
        for (int r = l; r <= n; ++r) {
            for (int i = 1, j = 1; i <= n; ++i) {
                while (j <= i && check(l, j, r, i)) ++j;
                ans += j - 1;
            }
        }

    cout << ans << '\n';
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