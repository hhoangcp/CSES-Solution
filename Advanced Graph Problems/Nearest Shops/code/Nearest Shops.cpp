#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <tuple>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <bitset>
#include <iomanip>
#include <random>
#include <sstream>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int128 __int128
#define uint128 __uint128_t
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int, int>
#define pil pair<int, ll>
#define pli pair<ll, int>
#define pll pair<ll, ll>
#define fst first
#define snd second
#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define mp make_pair
#define mt make_tuple

using namespace std;
using namespace chrono;

vector<int> V[200006];
int dist[200006], ans[200006], src[200006];
bool visited[200006], shop[200006];

void solve() {
    int n, m, k; cin >> n >> m >> k;

    queue<int> Q;
    for (int i = 1; i <= n; ++i) dist[i] = INT_MAX;

    for (int i = 1; i <= k; ++i) {
        int u; cin >> u;
        if (!shop[u]) {
            Q.push(u);
            dist[u] = 0;
            visited[u] = shop[u] = true;
            src[u] = u;
        }
    }

    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        V[u].pub(v);
        V[v].pub(u);
    }

    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (int v: V[u])
            if (!visited[v]) {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                src[v] = src[u];
                Q.push(v);
            }
    }

    for (int i = 1; i <= n; ++i) {
        ans[i] = dist[i];
        if (shop[i]) ans[i] = INT_MAX;
    }

    for (int u = 1; u <= n; ++u)
        for (int v: V[u]) {
            if (src[u] == src[v]) continue;

            int d = dist[u] + dist[v] + 1;
            ans[src[u]] = min(ans[src[u]], d);
            ans[src[v]] = min(ans[src[v]], d);
        }

    for (int i = 1; i <= n; ++i) {
        if (ans[i] == INT_MAX) ans[i] = -1;
        cout << ans[i] << ' ';
    }

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
