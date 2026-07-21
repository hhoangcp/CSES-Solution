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

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

ll a[46];
ll sumA[(1 << 20) + 6], sumB[(1 << 20) + 6], tmp[(1 << 20) + 6];
int ordA[(1 << 20) + 6], ordB[(1 << 20) + 6];

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    int m = n >> 1;
    for (int i = 0; i < m; ++i) {
        int half = 1 << i, len = half << 1;
        for (int mask = 0; mask < half; ++mask) sumA[mask | (1 << i)] = sumA[mask] + a[i];

        int p = half - 1, q = half - 1, r = len - 1;
        while (p >= 0 || q >= 0) {
            if (q < 0 || (p >= 0 && sumA[ordA[p]] > sumA[ordA[q] | (1 << i)]))
                ordA[r--] = ordA[p--];
            else
                ordA[r--] = ordA[q--] | (1 << i);
        }
    }

    for (int i = 0; i < (1 << m); ++i)
        tmp[i] = sumA[ordA[i]];
    memcpy(sumA, tmp, sizeof(ll) * (1 << m));

    for (int i = 0; i < n - m; ++i) {
        int half = 1 << i, len = half << 1;
        for (int mask = 0; mask < half; ++mask) sumB[mask | (1 << i)] = sumB[mask] + a[i + m];

        int p = half - 1, q = half - 1, r = len - 1;
        while (p >= 0 || q >= 0) {
            if (q < 0 || (p >= 0 && sumB[ordB[p]] > sumB[ordB[q] | (1 << i)]))
                ordB[r--] = ordB[p--];
            else
                ordB[r--] = ordB[q--] | (1 << i);
        }
    }

    for (int i = 0; i < (1 << (n - m)); ++i)
        tmp[i] = sumB[ordB[i]];
    memcpy(sumB, tmp, sizeof(ll) * (1 << (n - m)));

    auto countLess = [&] (const ll &s) -> bool {
        ll sum = 0;
        for (int i = (1 << m) - 1, j = 0; i >= 0; --i) {
            while (j < (1 << (n - m)) && sumA[i] + sumB[j] < s) ++j;
            sum += j;
        }

        return sum <= s;
    };

    ll lo = *min_element(a, a + n), hi = accumulate(a, a + n, 0LL);
    while (lo < hi) {
        ll mid = (lo + hi + 1) >> 1;

        if (countLess(mid)) lo = mid;
        else hi = mid - 1;
    }

    ll sum = lo;
    ll mask1 = -1, mask2 = -1;
    for (int i = (1 << m) - 1, j = 0; i >= 0 && mask2 == -1; --i) {
        while (j < (1 << (n - m)) && sumA[i] + sumB[j] < sum) ++j;

        int p = j;
        while (p < (1 << (n - m)) && sumA[i] + sumB[p] == sum && mask2 == -1) {
            if (mask1 == -1) {
                mask1 = (static_cast<ll>(ordB[p]) << m) | ordA[i];
            } else {
                mask2 = (static_cast<ll>(ordB[p]) << m) | ordA[i];
            }

            ++p;
        }
    }

    ll common = mask1 & mask2;
    mask1 ^= common, mask2 ^= common;
    cout << __builtin_popcountll(mask1) << '\n';
    for (int i = 0; i < n; ++i)
        if (mask1 & (1LL << i)) cout << a[i] << ' ';
    cout << '\n';

    cout << __builtin_popcountll(mask2) << '\n';
    for (int i = 0; i < n; ++i)
        if (mask2 & (1LL << i)) cout << a[i] << ' ';
    cout << '\n';
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