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

ll get_coordinate(ll len, ll k) {
    ll cycle = 2 * (len - 1);
    ll rem = k % cycle;

    if (rem <= len - 1) {
        return 1 + rem;
    } else {
        return len - (rem - (len - 1));
    }
}

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;

    ll final_r = get_coordinate(n, k);
    ll final_c = get_coordinate(m, k);

    ll term1 = k / (n - 1);
    ll term2 = k / (m - 1);
    ll lcm_val = ((__int128)(n - 1) * (m - 1)) / gcd(n - 1, m - 1);

    ll term3 = k / lcm_val;
    ll bounces = term1 + term2 - term3;

    cout << final_r << " " << final_c << " " << bounces << "\n";
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
