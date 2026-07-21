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

struct Data {
    int u, v, cnt_v;
};

vector<Data> S;
int cnt[100006];

int Find(int u) {
    if (cnt[u] < 0) return u;
    return Find(cnt[u]);
}

bool Union(int u, int v) {
    u = Find(u), v = Find(v);
    if (u == v) return false;

    if (cnt[u] > cnt[v]) swap(u, v);
    S.pub({u, v, cnt[v]});
    cnt[u] += cnt[v];
    cnt[v] = u;

    return true;
}

void Rollback(int t) {
    for (int i = S.size(); i --> t;) {
        int u = S[i].u, v = S[i].v, cnt_v = S[i].cnt_v;
        cnt[v] = cnt_v;
        cnt[u] -= cnt[v];
    }

    S.resize(t);
}

struct Edge {
    int u, v, w, p;
} E[200006];

struct Layer {
    vector<int> ids;
    int pos;
};

map<int, vector<int>> edgeW;
map<int, vector<Layer>> layers;

bool ans[200006];

void solve() {
    int n, m, q; cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i) cnt[i] = -1;

    for (int i = 1; i <= m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        E[i] = {u, v, w};
        edgeW[w].pub(i);
    }

    for (int i = 1; i <= q; ++i) {
        int k; cin >> k;
        ans[i] = true;

        map<int, vector<int>> tmp;
        while (k--) {
            int p; cin >> p;
            tmp[E[p].w].pub(p);
        }

        for (const auto& [w, ids]: tmp)
            layers[w].pub({ids, i});
    }

    for (const auto& [w, idsE]: edgeW) {
        for (const auto& [ids, pos]: layers[w]) {
            int t = S.size();

            for (int id: ids) {
                int u = E[id].u, v = E[id].v;
                ans[pos] &= Union(u, v);
            }

            Rollback(t);
        }

        for (int id: idsE) {
            int u = E[id].u, v = E[id].v;
            Union(u, v);
        }
    }

    for (int i = 1; i <= q; ++i)
        if (ans[i]) cout << "YES\n";
        else cout << "NO\n";
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
