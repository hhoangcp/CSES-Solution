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

struct Edge {
    int u, v, w, p;
} E[200006];

int cnt[100006];

int Find(int u) {
    if (cnt[u] < 0) return u;
    return cnt[u] = Find(cnt[u]);
}

bool Union(int u, int v) {
    u = Find(u), v = Find(v);
    if (u == v) return false;

    if (cnt[u] > cnt[v]) swap(u, v);
    cnt[u] += cnt[v];
    cnt[v] = u;

    return true;
}

const int H = 16;
vector<pii> V[100006];
int par[100006][18], mx[100006][18], depth[100006];

void DFS(int u) {
    for (int i = 1; i <= H; ++i) {
        par[u][i] = par[par[u][i - 1]][i - 1];
        mx[u][i] = max(mx[u][i - 1], mx[par[u][i - 1]][i - 1]);
    }

    for (auto [v, w]: V[u])
        if (par[u][0] != v) {
            par[v][0] = u;
            depth[v] = depth[u] + 1;
            mx[v][0] = w;
            DFS(v);
        }
}

int mx_query(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);

    int ans = 0;
    for (int i = H, mask = depth[v] - depth[u]; i >= 0; --i)
        if (mask & (1 << i)) {
            ans = max(ans, mx[v][i]);
            v = par[v][i];
        }

    if (u == v) return ans;

    for (int i = H; i >= 0; --i)
        if (par[u][i] != par[v][i]) {
            ans = max(ans, mx[u][i]);
            ans = max(ans, mx[v][i]);
            u = par[u][i], v = par[v][i];
        }

    ans = max(ans, mx[u][0]);
    ans = max(ans, mx[v][0]);
    return ans;
}

bool ans[200006];

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) cnt[i] = -1;
    for (int i = 1; i <= m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        E[i] = {u, v, w, i};
    }

    sort(E + 1, E + m + 1, [&] (const Edge &a, const Edge &b) { return a.w < b.w; });

    for (int i = 1; i <= m; ++i) {
        int u = E[i].u, v = E[i].v, w = E[i].w;
        if (Union(u, v)) {
            V[u].pub({v, w});
            V[v].pub({u, w});
        }
    }

    DFS(1);

    for (int i = 1; i <= m; ++i) {
        int u = E[i].u, v = E[i].v, w = E[i].w, p = E[i].p;

        if (mx_query(u, v) >= w) {
            ans[p] = true;
        } else {
            ans[p] = false;
        }
    }

    for (int i = 1; i <= m; ++i) {
        if (ans[i]) cout << "YES\n";
        else cout << "NO\n";
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
