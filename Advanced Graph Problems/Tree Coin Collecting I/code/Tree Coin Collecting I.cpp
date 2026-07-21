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

const int INF = 1e9 + 7;
const int H = 17;
vector<int> V[200006];
int par[200006][18], mn[200006][18], depth[200006], val[200006];

void DFS(int u) {
    for (int i = 1; i <= H; ++i) {
        par[u][i] = par[par[u][i - 1]][i - 1];
        mn[u][i] = min(mn[u][i - 1], mn[par[u][i - 1]][i - 1]);
    }

    for (int v: V[u])
        if (par[u][0] != v) {
            par[v][0] = u;
            depth[v] = depth[u] + 1;
            DFS(v);
        }
}

int lca(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);

    for (int i = H, mask = depth[v] - depth[u]; i >= 0; --i)
        if ((mask >> i) & 1) v = par[v][i];

    if (u == v) return u;

    for (int i = H; i >= 0; --i)
        if (par[u][i] != par[v][i]){
            u = par[u][i];
            v = par[v][i];
        }

    return par[u][0];
}

int dist(int u, int v) {
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
}

int mn_query(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);

    int ans = INF;
    for (int i = H, mask = depth[v] - depth[u]; i >= 0; --i)
        if (mask & (1 << i)) {
            ans = min(ans, mn[v][i]);
            v = par[v][i];
        }

    if (u == v) return min(ans, val[v]);

    for (int i = H; i >= 0; --i)
        if (par[u][i] != par[v][i]) {
            ans = min(ans, mn[u][i]);
            ans = min(ans, mn[v][i]);
            u = par[u][i], v = par[v][i];
        }

    ans = min(ans, mn[u][0]);
    ans = min(ans, mn[v][0]);
    ans = min(ans, val[par[v][0]]);

    return ans;
}

void solve() {
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; ++i) val[i] = INF;

    queue<int> Q;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;

        if (x == 1) {
            Q.push(i);
            val[i] = 0;
        }
    }

    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        V[u].pub(v);
        V[v].pub(u);
    }

    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (int v: V[u])
            if (val[v] > val[u] + 1) {
                val[v] = val[u] + 1;
                Q.push(v);
            }
    }

    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= H; ++j) mn[i][j] = INF;

    for (int i = 1; i <= n; ++i) mn[i][0] = val[i];
    DFS(1);

    while (q--) {
        int u, v; cin >> u >> v;
        cout << dist(u, v) + 2 * mn_query(u, v) << '\n';
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