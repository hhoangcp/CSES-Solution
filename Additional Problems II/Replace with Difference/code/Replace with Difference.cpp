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

const int MAX_SUM = 1000001;
bitset<MAX_SUM> dp[1001];

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    long long total_sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total_sum += a[i];
    }

    if (total_sum % 2 != 0) {
        cout << -1 << endl;
        return;
    }

    int target = total_sum / 2;
    dp[0].reset();
    dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        dp[i + 1] = dp[i] | (dp[i] << a[i]);
    }

    if (!dp[n][target]) {
        cout << -1 << endl;
        return;
    }

    priority_queue<int> pq_P;
    priority_queue<int> pq_N;

    int cur_w = target;
    for (int i = n; i > 0; i--) {
        if (cur_w >= a[i - 1] && dp[i - 1][cur_w - a[i - 1]]) {
            pq_P.push(a[i - 1]);
            cur_w -= a[i - 1];
        } else {
            pq_N.push(a[i - 1]);
        }
    }

    while (pq_P.size() + pq_N.size() > 1) {
        if (pq_P.empty()) {
            int x = pq_N.top(); pq_N.pop();
            int y = pq_N.top(); pq_N.pop();
            cout << x << " " << y << endl;
            pq_N.push(abs(x - y));
            continue;
        }
        if (pq_N.empty()) {
            int x = pq_P.top(); pq_P.pop();
            int y = pq_P.top(); pq_P.pop();
            cout << x << " " << y << endl;
            pq_P.push(abs(x - y));
            continue;
        }

        int p_val = pq_P.top(); pq_P.pop();
        int n_val = pq_N.top(); pq_N.pop();

        cout << p_val << " " << n_val << endl;

        int diff = abs(p_val - n_val);

        if (p_val >= n_val) {
            pq_P.push(diff);
        } else {
            pq_N.push(diff);
        }
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
