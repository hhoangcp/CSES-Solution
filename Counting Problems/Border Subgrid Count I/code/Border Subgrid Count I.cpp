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

static char a[3006][3006];
static sint L[3006][3006], R[3006][3006], U[3006][3006], D[3006][3006];
static ll ans[26];
int n, K;

static int fw[3006], fwN;

inline void fw_clear() {
    memset(fw, 0, sizeof(fw));
}
inline void fw_add(int i) {
    for (++i; i <= fwN; i += i & -i) ++fw[i];
}
inline int fw_sum(int i) {
    int s = 0;
    for (; i > 0; i -= i & -i) s += fw[i];
    return s;
}

static unsigned long long mask[3006];

inline int pref(int x) {
    if (x <= 0) return 0;
    int b = x >> 6;
    return fw_sum(b) +
           __builtin_popcountll(mask[b] & ((1ULL << (x & 63)) - 1));
}

static int tmp_u[3006], tmp_d[3006], tmp_c[3006];
static int head[3007], val[9000005], nxt[9000005];
int ptr;

inline void solveDiagonal(int sr, int sc, int len) {
    fw_clear();
    memset(mask, 0, sizeof(mask));
    memset(head, 0, sizeof(head));
    ptr = 0;

    int tot = 0;

    auto flush = [&](int x) {
        for (int p = head[x]; p; p = nxt[p]) {
            ++tot;
            int pos = val[p];
            int b = pos >> 6;
            fw_add(b);
            mask[b] ^= 1ULL << (pos & 63);
        }
        head[x] = 0;
    };

    for (int k = 0; k < len; ++k) {
        int c = tmp_c[k];

        flush(k);

        int nx = k + tmp_u[k];
        val[++ptr] = k;
        nxt[ptr] = head[nx];
        head[nx] = ptr;

        int b = tmp_d[k];
        int left = k + 1 - b;
        if (left < 0) left = 0;

        ans[c] += b;
        ans[c] -= (tot - pref(left));
    }

    flush(len);
}

void solve() {
    cin >> n >> K;
    fwN = (n >> 6) + 2;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];

    /* R, D */
    for (int i = n - 1; i >= 0; --i)
        for (int j = n - 1; j >= 0; --j) {
            R[i][j] = (j + 1 < n && a[i][j] == a[i][j + 1]) ? R[i][j + 1] + 1 : 1;
            D[i][j] = (i + 1 < n && a[i][j] == a[i + 1][j]) ? D[i + 1][j] + 1 : 1;
        }

    /* L, U */
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            L[i][j] = (j && a[i][j] == a[i][j - 1]) ? L[i][j - 1] + 1 : 1;
            U[i][j] = (i && a[i][j] == a[i - 1][j]) ? U[i - 1][j] + 1 : 1;
        }

    /* diagonals */
    for (int d = -(n - 1); d < n; ++d) {
        int r = max(0, d);
        int c = max(0, -d);
        int len = min(n - r, n - c);

        for (int k = 0; k < len; ++k) {
            int i = r + k, j = c + k;
            tmp_c[k] = a[i][j] - 'A';
            tmp_u[k] = min((int)R[i][j], (int)D[i][j]);
            tmp_d[k] = min((int)L[i][j], (int)U[i][j]);
        }
        if (len > 0) solveDiagonal(r, c, len);
    }

    for (int i = 0; i < K; ++i)
        cout << ans[i] << '\n';
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
