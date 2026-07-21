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

using namespace std;
using namespace chrono;

vector<int> V[2506];
int dist[2506][2506][2];
int n, m;

void BFS(int s) {
    for(int u = 1; u <= n; ++u) dist[s][u][0] = dist[s][u][1] = -1;

    queue<pii> Q; Q.push({s, 0}); dist[s][s][0] = 0;
    while(!Q.empty()) {
        int u = Q.front().fst, odd = Q.front().snd; Q.pop();

        for(int v: V[u])
            if (dist[s][v][1 - odd] == -1) {
                dist[s][v][1 - odd] = dist[s][u][odd] + 1;
                Q.push({v, 1 - odd});
            }
    }
}

void solve() {
    int q; cin >> n >> m >> q;
    for(int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        V[u].pub(v);
        V[v].pub(u);
    }

    for(int s = 1; s <= n; ++s) BFS(s);

    while(q--) {
        int u, v, d; cin >> u >> v >> d;

        if (dist[u][v][d % 2] != -1 && dist[u][v][d % 2] <= d) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
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
