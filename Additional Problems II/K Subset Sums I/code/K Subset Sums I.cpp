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
    int n, k; cin >> n >> k;

    vector<ll> a(n);
    ll min_sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < 0) {
            min_sum += a[i];
            a[i] = -a[i];
        }
    }

    sort(all(a));

    vector<ll> results;
    results.pub(min_sum);

    if (k > 1) {
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        pq.push({a[0], 0});

        while (results.size() < k && !pq.empty()) {
            pair<ll, int> curr = pq.top();
            pq.pop();

            ll s = curr.fst;
            int i = curr.snd;

            results.pub(s + min_sum);

            if (i + 1 < n) {
                pq.push({s + a[i + 1], i + 1});
                pq.push({s - a[i] + a[i + 1], i + 1});
            }
        }
    }

    for (int i = 0; i < k; i++) cout << results[i] << ' ';
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
