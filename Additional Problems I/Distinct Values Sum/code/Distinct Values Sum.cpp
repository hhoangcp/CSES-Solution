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

void solve() {
    int n; cin >> n;

    map<int, vi> pos;

    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        pos[x].pub(i);
    }

    ll ans = 0;
    for (auto [x, vec]: pos) {
        ll tot = 1LL * n * (n + 1) / 2;

        tot -= 1LL * vec[0] * (vec[0] - 1) / 2;
        tot -= 1LL * (n - vec.back()) * (n - vec.back() + 1) / 2;

        for (int i = 1; i < (int) vec.size(); ++i) {
            int len = vec[i] - vec[i - 1] - 1;
            tot -= 1LL * len * (len + 1) / 2;
        }

        ans += tot;
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
