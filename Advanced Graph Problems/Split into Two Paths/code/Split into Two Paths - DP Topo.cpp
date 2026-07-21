
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

vector<int> V[200006];
int indeg[200006], ord[200006], topo[200006], ntopo = 0;
int gap[200006], pref[200006], pre[200006], color[200006];

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        V[u].pub(v);
        ++indeg[v];
    }

    queue<int> Q;
    for (int u = 1; u <= n; ++u)
        if (indeg[u] == 0) Q.push(u);

    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        topo[++ntopo] = u;
        ord[u] = ntopo;
        for (int v : V[u])
            if (--indeg[v] == 0) Q.push(v);
    }

    if (ntopo < n) {
        cout << "NO\n";
        return;
    }

    pref[1] = 0;
    for (int i = 2; i <= n; ++i) {
        bool has_edge = false;
        for (int v : V[topo[i - 1]]) {
            if (v == topo[i]) {
                has_edge = true;
                break;
            }
        }
        if (!has_edge) gap[i] = 1;
        pref[i] = pref[i - 1] + gap[i];
    }

    auto isPath = [&](int l, int r) {
        if (l >= r) return true;
        return pref[r] - pref[l] == 0;
    };

    for (int i = 1; i <= n; ++i) pre[i] = -1;
    pre[1] = 0;

    for (int h = 2; h <= n; ++h) {
        if (isPath(1, h - 1)) pre[h] = 1;
        else break;
    }

    for (int i = 1; i <= n; ++i) {
        if (pre[i] == -1) continue;

        if (isPath(i, n)) {
            cout << "YES\n";
            int cur = i;
            int c = 1;
            for (int k = i; k <= n; ++k) color[k] = c;

            while (cur > 0) {
                int last = pre[cur];
                c ^= 3;
                for (int k = last; k < cur; k++) color[k] = c;
                cur = last;
            }

            vector<int> p1, p2;
            for (int k = 1; k <= n; ++k) {
                if (color[k] == 1) p1.pub(topo[k]);
                else p2.pub(topo[k]);
            }

            cout << p1.size();
            for (int x : p1) cout << " " << x;
            cout << "\n";
            cout << p2.size();
            for (int x : p2) cout << " " << x;
            cout << "\n";
            return;
        }

        if (i > 1) {
            int u = topo[i - 1];
            for (int v : V[u]) {
                int j = ord[v];
                if (j > i && isPath(i, j - 1)) {
                    if (pre[j] == -1) pre[j] = i;
                }
            }
        }
    }

    cout << "NO\n";
}

int main() {
    //freopen("test_input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tests = 1;
    for (int i = 0; i < tests; ++i) {
        solve();
    }

    return 0;
}