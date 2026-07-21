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

ll ceil_div(ll a, ll b) {
    return (a + b - 1) / b;
}

void solve() {
    int n, m; cin >> n >> m;

    vector<ll> a(n);
    ll g_min = 2e18;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < g_min) g_min = a[i];
    }

    vector<ll> H(m + 1), L(m + 1);
    vector<pair<ll, ll>> seg(m + 1);
    priority_queue<array<ll, 3>> pq;

    for (int i = 0; i < n; i++) pq.push({a[i], 1, (ll)i});

    ll cur_min = g_min;
    for (int k = 0; k <= m; k++) {
        auto [val, p, id] = pq.top();
        H[k] = val;
        seg[k] = {cur_min, val};
        if (k < m) {
            pq.pop();
            p++;
            ll next_min = a[id] / p;
            if (next_min < cur_min) cur_min = next_min;
            pq.push({ceil_div(a[id], p), p, id});
        }
    }

    while (!pq.empty()) pq.pop();
    cur_min = g_min;
    for (int i = 0; i < n; i++) {
        if (a[i] > 1) pq.push({a[i] / 2, 2, (ll)i});
    }

    L[0] = cur_min;
    for (int k = 1; k <= m; k++) {
        if (pq.empty()) {
            L[k] = L[k - 1];
            continue;
        }
        auto [val, p, id] = pq.top();
        pq.pop();
        if (val < cur_min) cur_min = val;
        L[k] = cur_min;
        ll next_val = a[id] / (p + 1);
        if (next_val > 0) pq.push({next_val, p + 1, id});
    }

    multiset<ll> st;
    int pA = 0, pR = 0;
    for (int k = 1; k <= m; k++) {
        while (pA <= m && seg[pA].snd >= H[k]) {
            st.insert(seg[pA].snd - seg[pA].fst);
            pA++;
        }
        while (pR < pA && seg[pR].fst > L[k]) {
            auto it = st.find(seg[pR].snd - seg[pR].first);
            if (it != st.end()) st.erase(it);
            pR++;
        }
        ll ans = st.empty() ? 2e18 : *st.begin();
        if (pR > 0) ans = min(ans, seg[pR - 1].snd - L[k]);

        cout << ans << (k == m ? "" : " ");
    }
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
