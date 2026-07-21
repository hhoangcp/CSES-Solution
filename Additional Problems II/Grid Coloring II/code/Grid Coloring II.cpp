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

struct TwoSAT {
    int n;
    vector<vi> adj;
    vi dfn, low, scc;
    vector<bool> in_stk;
    stack<int> stk;
    int timer, scc_cnt;

    TwoSAT(int _n) : n(_n), adj(2 * _n), dfn(2 * _n, 0), low(2 * _n, 0),
                     scc(2 * _n, 0), in_stk(2 * _n, false), timer(0), scc_cnt(0) {}

    void add_edge(int u, int v) {
        adj[u].push_back(v);
    }

    void add_conflict(int u, int val_u, int v, int val_v) {
        int node_u = 2 * u + val_u;
        int node_v = 2 * v + val_v;
        add_edge(node_u, node_v ^ 1);
        add_edge(node_v, node_u ^ 1);
    }

    void tarjan(int u) {
        dfn[u] = low[u] = ++timer;
        stk.push(u);
        in_stk[u] = true;
        for (int v : adj[u]) {
            if (!dfn[v]) {
                tarjan(v);
                low[u] = min(low[u], low[v]);
            } else if (in_stk[v]) {
                low[u] = min(low[u], dfn[v]);
            }
        }
        if (low[u] == dfn[u]) {
            scc_cnt++;
            while (true) {
                int v = stk.top();
                stk.pop();
                in_stk[v] = false;
                scc[v] = scc_cnt;
                if (u == v) break;
            }
        }
    }

    vector<int> solve() {
        for (int i = 0; i < 2 * n; ++i) if (!dfn[i]) tarjan(i);
        vector<int> res(n);
        for (int i = 0; i < n; ++i) {
            if (scc[2 * i] == scc[2 * i + 1]) return {};
            res[i] = (scc[2 * i] < scc[2 * i + 1] ? 0 : 1);
        }
        return res;
    }
};

void solve() {
    int n, m; cin >> n >> m;

    vector<string> grid(n);
    for (auto &row : grid) cin >> row;

    auto get_id = [&](int r, int c) { return r * m + c; };
    vector<pair<char, char>> options(n * m);
    TwoSAT ts(n * m);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            string opts = "";
            for (char c : {'A', 'B', 'C'}) if (c != grid[i][j]) opts += c;
            options[get_id(i, j)] = {opts[0], opts[1]};
        }
    }

    auto check_and_add = [&](int u, int v) {
        for (int i : {0, 1}) {
            for (int k : {0, 1}) {
                char char_u = (i == 0 ? options[u].first : options[u].second);
                char char_v = (k == 0 ? options[v].first : options[v].second);
                if (char_u == char_v) ts.add_conflict(u, i, v, k);
            }
        }
    };

    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            if (c + 1 < m) check_and_add(get_id(r, c), get_id(r, c + 1));
            if (r + 1 < n) check_and_add(get_id(r, c), get_id(r + 1, c));
        }
    }

    auto assignment = ts.solve();
    if (assignment.empty()) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    for (int i = 0; i < n * m; ++i) {
        int r = i / m, c = i % m;
        grid[r][c] = (assignment[i] == 0 ? options[i].first : options[i].second);
    }

    for (const auto &row : grid) cout << row << "\n";
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
