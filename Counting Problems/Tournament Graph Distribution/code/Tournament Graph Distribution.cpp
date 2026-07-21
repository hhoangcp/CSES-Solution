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

static const int MOD = 1e9 + 7;
static const int MAXN = 500;

ll C[MAXN+1][MAXN+1], p2[MAXN*(MAXN-1)/2 + 1], T[MAXN+1], dp[MAXN+1][MAXN+1];

inline long long add(long long a, long long b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}

inline long long mul(long long a, long long b) {
    return (a * b) % MOD;
}

void solve() {
    int n; cin >> n;

    for (int i = 0; i <= n; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = add(C[i-1][j-1], C[i-1][j]);
    }

    int maxE = n * (n - 1) / 2;
    p2[0] = 1;
    for (int i = 1; i <= maxE; i++)
        p2[i] = mul(p2[i-1], 2);

    T[1] = 1;
    for (int i = 2; i <= n; i++) {
        long long bad = 0;
        for (int j = 1; j < i; j++) {
            bad = add(bad,
                mul(C[i][j],
                    mul(T[j],
                        p2[(i-j)*(i-j-1)/2])));
        }
        T[i] = (p2[i*(i-1)/2] - bad + MOD) % MOD;
    }

    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= i; k++) {
            long long cur = 0;
            for (int s = 1; s <= i; s++) {
                if (i - s < 0) break;
                cur = add(cur, mul(dp[i-s][k-1], mul(C[i-1][s-1], T[s])));
            }
            dp[i][k] = cur;
        }
    }

    ll fact = 1;
    for (int k = 1; k <= n; k++) {
        (fact *= k) %= MOD;
        cout << dp[n][k] * fact % MOD  << '\n';
    }
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
