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

const ll MOD = 1e9+7;

using Mat = vector<vector<ll>>;

Mat mul(const Mat &A, const Mat &B) {
    Mat C(2, vector<ll>(2, 0));
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
    return C;
}

Mat power(Mat a, ll n) {
    Mat res = {{1, 0}, {0, 1}};
    while (n > 0) {
        if (n & 1) res = mul(res, a);
        a = mul(a, a);
        n >>= 1;
    }
    return res;
}

void solve() {
    ll n, k;
    cin >> n >> k;

    vector<ll> expo;
    ll tmp = k;
    for (ll p = 2; p * p <= tmp; p++) {
        if (tmp % p == 0) {
            ll e = 0;
            while (tmp % p == 0) {
                tmp /= p;
                e++;
            }
            expo.push_back(e);
        }
    }

    if (tmp > 1) expo.push_back(1);

    ll ans = 1;
    for (ll e : expo) {
        Mat M = {
            {1, 1},
            {e, 0}
        };

        Mat R = power(M, n - 1);

        ll f1 = 1;
        ll g1 = e;

        ll fn = (R[0][0] * f1 + R[0][1] * g1) % MOD;
        ll gn = (R[1][0] * f1 + R[1][1] * g1) % MOD;

        ll ways = (fn + gn) % MOD;
        ans = ans * ways % MOD;
    }

    cout << ans << "\n";
}

int main() {
    //freopen("test_input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tests = 1; cin >> tests;
    for (int i = 0; i < tests; ++i) {
        solve();
    }

    return 0;
}
