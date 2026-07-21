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

struct State {
    ll sum;
    int k, pos, limit;

    bool operator>(const State& other) const {
        return sum > other.sum;
    }
};

void solve() {
    int n, m, k_req;
    cin >> n >> m >> k_req;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    long long current_sum = 0;
    for (int i = 0; i < m; ++i) {
        current_sum += a[i];
    }

    priority_queue<State, vector<State>, greater<State>> pq;
    pq.push({current_sum, m - 1, m - 1, n});

    vector<long long> results;
    results.reserve(k_req);

    while (results.size() < k_req && !pq.empty()) {
        State top = pq.top();
        pq.pop();

        results.push_back(top.sum);

        if (top.pos + 1 < top.limit) {
            long long new_sum = top.sum - a[top.pos] + a[top.pos + 1];
            pq.push({new_sum, top.k, top.pos + 1, top.limit});
        }

        if (top.k > 0 && top.k < top.pos) {
            long long new_sum = top.sum - a[top.k - 1] + a[top.k];
            pq.push({new_sum, top.k - 1, top.k, top.pos});
        }
    }

    for (int i = 0; i < results.size(); ++i) {
        cout << results[i] << (i == results.size() - 1 ? "" : " ");
    }
    cout << endl;
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
