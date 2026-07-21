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

uint32_t mask[3006][3006];
char a[3006][3006];
bool hasAns[3006][3006];

void solve() {
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            mask[i][j] = (1 << (a[i][j] - 'A'));
        }
    }

    ll ans = 0;
    uint32_t full = (1 << k) - 1;
    for (int l = 1; l <= n; l <<= 1) {
        for (int i = l - 1; i < n; ++i)
            for (int j = l - 1; j < n; ++j) {
                if (hasAns[i][j]) continue;

                uint32_t Mask = mask[i][j];
                if (i >= l) Mask |= mask[i - l][j];
                if (j >= l) Mask |= mask[i][j - l];
                if (i >= l && j >= l) Mask |= mask[i - l][j - l];

                if (Mask == full) {
                    int lo = 0, hi = l;
                    while (lo < hi) {
                        int mid = lo + (hi - lo) / 2;
                        uint32_t MMask = mask[i][j];
                        if (i >= mid) MMask |= mask[i - mid][j];
                        if (j >= mid) MMask |= mask[i][j - mid];
                        if (i >= mid && j >= mid) MMask |= mask[i - mid][j - mid];

                        if (MMask == full) hi = mid;
                        else lo = mid + 1;
                    }

                    hasAns[i][j] = true;
                    ans += max(0, min(i + 1, j + 1) - (l + lo) + 1);
                }
            }

        for (int i = n - 1; i >= l; --i)
            for (int j = 0; j < n; ++j) mask[i][j] |= mask[i - l][j];

        for (int i = 0; i < n; ++i)
            for (int j = n - 1; j >= l; --j) mask[i][j] |= mask[i][j - l];
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