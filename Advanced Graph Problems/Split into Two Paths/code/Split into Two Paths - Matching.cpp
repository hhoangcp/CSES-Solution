#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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

static char buf[1 << 20], *p1 = buf, *p2 = buf;
#define get_char() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin), p1 == p2) ? EOF : *p1++)

inline int read() {
    int x = 0; char ch = get_char();
    while (ch < '0' || ch > '9') ch = get_char();
    while (ch >= '0' && ch <= '9') x = x * 10 + (ch - '0'), ch = get_char();
    return x;
}

static char out_buf[1 << 20];
int out_ptr = 0;

inline void write_char(char c) {
    if (out_ptr == (1 << 20)) fwrite(out_buf, 1, 1 << 20, stdout), out_ptr = 0;
    out_buf[out_ptr++] = c;
}

inline void write_int(int x) {
    if (x == 0) { write_char('0'); return; }
    static char s[12]; int top = 0;
    while (x) s[top++] = x % 10 + '0', x /= 10;
    while (top--) write_char(s[top]);
}

inline void flush_out() { fwrite(out_buf, 1, out_ptr, stdout), out_ptr = 0; }

const int MAXN = 200005;
const int MAXM = 500005;
const int INF = 1e9;

struct Edge { int u, v; } edges[MAXM];
int head[MAXN], to[MAXM], matchL[MAXN], matchR[MAXN], dist[MAXN], ptr[MAXN], q[MAXN];
int n, m, matching;

bool bfs() {
    int h = 0, t = 0;
    bool found = false;
    for (int i = 1; i <= n; i++) {
        if (!matchL[i]) { dist[i] = 0; q[t++] = i; }
        else dist[i] = INF;
    }
    while (h < t) {
        int u = q[h++];
        for (int i = head[u]; i < head[u + 1]; i++) {
            int v = to[i], w = matchR[v];
            if (!w) found = true;
            else if (dist[w] == INF) {
                dist[w] = dist[u] + 1;
                q[t++] = w;
            }
        }
    }
    return found;
}

bool dfs(int u) {
    for (int &i = ptr[u]; i < head[u + 1]; i++) {
        int v = to[i], w = matchR[v];
        if (!w || (dist[w] == dist[u] + 1 && dfs(w))) {
            matchL[u] = v; matchR[v] = u;
            return true;
        }
    }
    dist[u] = INF;
    return false;
}

void solve() {
    n = read(); m = read();
    if (n == 0) return;
    for (int i = 0; i < m; i++) edges[i] = {read(), read()};

    for (int i = 1; i <= n + 1; i++) head[i] = 0;
    for (int i = 0; i < m; i++) head[edges[i].u]++;
    for (int i = 1; i <= n; i++) head[i+1] += head[i];
    for (int i = n; i >= 1; i--) head[i] = head[i-1];
    head[1] = 0;

    static int cur_head[MAXN];
    for (int i = 1; i <= n; i++) cur_head[i] = head[i];
    for (int i = 0; i < m; i++) to[cur_head[edges[i].u]++] = edges[i].v;

    matching = 0;
    for (int u = 1; u <= n; u++) {
        for (int i = head[u]; i < head[u+1]; i++) {
            if (!matchR[to[i]]) {
                matchL[u] = to[i]; matchR[to[i]] = u;
                matching++; break;
            }
        }
    }

    while (matching < n - 2 && bfs()) {
        for (int i = 1; i <= n; i++) ptr[i] = head[i];
        for (int i = 1; i <= n; i++) {
            if (!matchL[i] && dfs(i)) {
                matching++;
                if (matching >= n - 2) break;
            }
        }
    }

    if (matching < n - 2) {
        write_char('N'); write_char('O'); write_char('\n');
    } else {
        write_char('Y'); write_char('E'); write_char('S'); write_char('\n');
        static bool vis[MAXN];
        static int in_deg[MAXN];
        for (int i = 1; i <= n; i++) {
            vis[i] = false;
            in_deg[i] = 0;
        }
        for (int i = 1; i <= n; i++) if (matchL[i]) in_deg[matchL[i]]++;

        int p_cnt = 0;
        for (int i = 1; i <= n && p_cnt < 2; i++) {
            if (!in_deg[i] && !vis[i]) {
                int curr = i, len = 0;
                static int path[MAXN];
                while (curr && !vis[curr]) {
                    vis[curr] = true;
                    path[len++] = curr;
                    curr = matchL[curr];
                }
                write_int(len);
                for (int j = 0; j < len; j++) { write_char(' '); write_int(path[j]); }
                write_char('\n');
                p_cnt++;
            }
        }
        while (p_cnt < 2) { write_char('0'); write_char('\n'); p_cnt++; }
    }
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

    flush_out();

    return 0;
}
