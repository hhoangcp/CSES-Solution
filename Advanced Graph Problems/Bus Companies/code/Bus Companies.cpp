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

vector<pii> V[200006];
ll dist[200006];
int cost[100006];

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; ++i) cin >> cost[i];

    for (int i = 1; i <= m; ++i) {
        int k; cin >> k;

        while (k--) {
            int v; cin >> v;
            V[n + i].pub({v, 0});
            V[v].pub({n + i, cost[i]});
        }
    }

    for (int i = 1; i <= n + m; ++i) dist[i] = LLONG_MAX;
    dist[1] = 0;
    priority_queue<pair<ll, int>> pq;
    pq.push({-dist[1], 1});
    while (!pq.empty()) {
        ll W = -pq.top().fst;
        int u = pq.top().snd;
        pq.pop();

        if (W > dist[u]) continue;

        for (pii e: V[u]) {
            int v = e.fst, w = e.snd;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({-dist[v], v});
            }
        }
    }

    for (int i = 1; i <= n; ++i) cout << dist[i] << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tests = 1; //cin >> tests;
    for (int i = 0; i < tests; ++i) {
        solve();
    }
}