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

struct DSU {
    vector<int> parent, sz;
    vector<ll> diff;
    // diff[x] = p_x - p_parent[x]

    DSU(int n) : parent(n), sz(n,1), diff(n,0) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] == x) return x;
        int p = parent[x];
        parent[x] = find(parent[x]);
        diff[x] += diff[p];
        return parent[x];
    }

    // enforce: p_v - p_u = w
    bool unite(int u, int v, ll w) {
        int ru = find(u);
        int rv = find(v);

        if (ru == rv) {
            // check consistency
            return (diff[v] - diff[u] == w);
        }

        // union by size
        if (sz[ru] < sz[rv]) {
            swap(ru, rv);
            swap(u, v);
            w = -w;
        }

        parent[rv] = ru;
        // want:
        // diff[v] + p_rv - (diff[u] + p_ru) = w
        // => p_rv - p_ru = diff[u] - diff[v] + w
        diff[rv] = diff[u] - diff[v] + w;
        sz[ru] += sz[rv];
        return true;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    DSU dsu(n + 1);

    for (int i = 0; i < m; i++) {
        int l, r;
        ll s; cin >> l >> r >> s;
        if (!dsu.unite(l - 1, r, s)) {
            cout << "NO\n";
            return;
        }
    }

    vector<ll> p(n + 1, 0);
    for (int i = 0; i <= n; i++) {
        dsu.find(i);
        p[i] = dsu.diff[i];
    }

    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
        cout << p[i] - p[i - 1] << " ";
    }
    cout << "\n";
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
