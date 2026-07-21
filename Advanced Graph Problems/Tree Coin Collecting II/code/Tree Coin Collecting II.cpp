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
int par[200006][18], depth[200006], val[200006];
int coin[200006], mask[200006], pre[200006];

void DFS(int u) {
    mask[u] = coin[u];

    for (int i = 1; i <= H; ++i) {
        par[u][i] = par[par[u][i - 1]][i - 1];
    }

    for (int v: V[u])
        if (par[u][0] != v) {
            par[v][0] = u;
            depth[v] = depth[u] + 1;
            DFS(v);
            mask[u] |= mask[v];
        }
}

int LCA(int u, int v) {
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

void Calc(int u) {
    for (int v: V[u])
        if (par[u][0] != v) {
            pre[v] = pre[u] + mask[v];
            Calc(v);
        }
}

void solve() {
    int n, q; cin >> n >> q;

    int root = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> coin[i];
        if (coin[i] == 1) root = i;
    }

    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        V[u].pub(v);
        V[v].pub(u);
    }

    DFS(root);

    pre[root] = mask[root];
    Calc(root);

    int base = accumulate(mask + 1, mask + n + 1, -1) * 2;

    while (q--) {
        int u, v; cin >> u >> v;
        int lca = LCA(u, v);
        int dist = depth[u] + depth[v] - 2 * depth[lca];

        if (pre[lca] != depth[lca] + 1) {
            int add = depth[lca] + 1 - pre[lca];
            cout << dist + base + 2 * add << '\n';
        } else {
            int tot = pre[u] + pre[v] - 2 * pre[par[lca][0]] - mask[lca];
            cout << base - 2 * max(0, tot - 1) + dist << '\n';
        }
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