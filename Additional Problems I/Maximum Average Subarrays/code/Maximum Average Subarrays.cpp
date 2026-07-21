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

ll S[200005];
int a[200005];
int hull[200005];

inline bool bad(int a, int b, int c) {
    // (S[b] - S[a]) / (b - a) >= (S[c] - S[b]) / (c - b)
    return (S[b] - S[a]) * (c - b) >= (S[c] - S[b]) * (b - a);
}

inline bool better(int k1, int k2, int i) {
    // slope(k1, i) < slope(k2, i)
    return (S[i] - S[k1]) * (i - k2) < (S[i] - S[k2]) * (i - k1);
}

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++)
        S[i] = S[i - 1] + a[i];

    int sz = 0;
    hull[sz++] = 0;

    for (int i = 1; i <= n; i++) {
        // add k = i-1
        int k = i - 1;
        while (sz >= 2 && bad(hull[sz - 2], hull[sz - 1], k))
            sz--;
        hull[sz++] = k;

        // binary search best k
        int l = 0, r = sz - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (better(hull[mid], hull[mid + 1], i))
                l = mid + 1;
            else
                r = mid;
        }

        cout << i - hull[l] << (i == n ? '\n' : ' ');
    }
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
