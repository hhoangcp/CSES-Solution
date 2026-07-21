#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define uint128 __uint128_t
#define int128 __int128
#define float128 __float128
#define ld long double
#define ll long long
#define ull unsigned ll
#define llong ll
#define ullong ull
#define ldouble long double
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
#define pil pair<ll, int>
#define pli pair<int, ll>
#define pll pair<ll, ll>
#define tiii tuple<int, int, int>
#define pld pair<ld, ld>
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define getbit(x, i) (((x) >> (i)) & 1)
#define cntbit(x) __builtin_popcount(x)
#define FOR(i,l,r) for (int i = l; i <= r; i++)
#define FORD(i,l,r) for (int i = l; i >= r; i--)

using namespace std;
using namespace __gnu_pbds;

const int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
const int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};

int n, a[200006], In[200006], Out[200006], bit[400006];

void update(int i, int val) {
    for(; i <= 2 * n; i += (i & (-i))) bit[i] += val;
}

int query(int i) {
    int ans = 0;
    for(; i > 0; i -= (i & (-i))) ans += bit[i];
    return ans;
}

int par[400006];

int Find(int u) {
    if (par[u] < 0) return u;
    return par[u] = Find(par[u]);
}

bool isSame(int u, int v) {
    return Find(u) == Find(v);
}

void Merge(int u, int v) {
    u = Find(u), v = Find(v);
    if (u == v) return;

    if (par[u] > par[v]) swap(u, v);
    par[u] += par[v]; par[v] = u;
}

bool inStack[200006];
int color[400006];

void solve() {
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];

    for(int i = 1, curr = 1, j = 1; i <= 2 * n; ++i) {
        if (inStack[curr]) {
            inStack[curr] = false;
            Out[curr] = i;
            ++curr;
        } else {
            inStack[a[j]] = true;
            In[a[j++]] = i;
        }
    }

    for(int i = 1; i <= n; ++i) {
        update(In[i], 1);
        par[i] = par[i + n] = -1;
    }

    /// 2-sat + DSU
    set<pii> X;
    for(int y = 1; y <= n; ++y) {
        update(In[y], -1);

        set<pii>::iterator it = X.upper_bound({In[y], -1000000000});
        if (it != X.begin()) --it;

        while (it != X.end()) {
            int x = it->snd; /// x < y
            int L = max(In[x], In[y]);
            int R = min(Out[x], Out[y]);

            set<pii>::iterator Del = X.end();
            if (L < R) {
                if (In[x] < In[y]) {
                    if (query(R) - query(L - 1) > 0) {
                        /// exist z: y < z and In[x] < In[y] < In[z] and Out[x] < Out[y] < Out[z]
                        cout << "IMPOSSIBLE\n";
                        return;
                    } else {
                        Merge(x, y + n);    
                        Merge(y, x + n);
                    }
                } else {
                    /// In[y] < In[x] < Out[x] < Out[y]
                    if (query(R) - query(L - 1) > 0) {
                        /// exist z: y < z and In[y] < min(In[x], In[z]) and  Out[x] < Out[y] < Out[z]
                        /// => color[x] == color[y] != color[z]
                        Merge(x, y);
                        Merge(x + n, y + n);
                    }

                    /// remove x
                    Del = it;
                }
            }

            ++it;
            if (Del != X.end()) X.erase(Del);
        }

        /// insert y
        X.insert({In[y], y});
    }

    /// check
    for(int i = 1; i <= n; ++i)
    if (isSame(i, i + n)) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    for(int i = 1; i <= n; ++i)
    if (color[Find(i)] == 0) {
        color[Find(i)] = 1;
        color[Find(i + n)] = 2;
    }

    for(int i = 1; i <= n; ++i) cout << color[Find(a[i])] << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int tests = 1; // cin >> tests;
    for(int test = 1; test <= tests; ++test) {
        solve();
    }

    return 0;
}
