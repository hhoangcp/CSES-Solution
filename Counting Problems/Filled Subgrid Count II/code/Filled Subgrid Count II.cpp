
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

ll ans[26];
int h[3006];
char a[3006][3006];

void solve() {
    int n, k; cin >> n >> k;

    for (int i = 1; i <= n; ++i) {
        vector<pii> st;
        ll sum = 0;

        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];

            if (a[i][j] == a[i - 1][j]) ++h[j];
            else h[j] = 1;

            if (a[i][j] != a[i][j - 1]) {
                st.clear();
                sum = 0;
            }

            int width = 1;
            while (!st.empty() && st.back().fst >= h[j]) {
                sum -= 1LL * st.back().fst * st.back().snd;
                width += st.back().snd;
                st.pob();
            }

            sum += 1LL * h[j] * width;
            st.pub(make_pair(h[j], width));

            ans[a[i][j] - 'A'] += sum;
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