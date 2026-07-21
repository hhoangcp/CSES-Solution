
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

struct TEdge {
    int u, v, c;

    bool operator < (const TEdge &other) const {
        return c < other.c;
    }
} E[200006];

int n, m, Rank[100006], Par[100006];

int Find(int u) {
    if (Par[u] != u) Par[u] = Find(Par[u]);
    return Par[u];
}

bool Union(int u, int v) {
    u = Find(u), v = Find(v);
    if (u == v) return false;

    if (Rank[u] == Rank[v]) ++Rank[u];
    if (Rank[u] > Rank[v]) Par[v] = u; else Par[u] = v;

    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int u, v, c; cin >> u >> v >> c;
        E[i] = {u, v, c};
    }

    for(int u = 1; u <= n; ++u) Par[u] = u;
    sort(E+1, E+m+1);

    llong res = 0; int cur = 0;
    for(int i = 1; i <= m; ++i)
    if (Union(E[i].u, E[i].v)) {
        ++cur; res += E[i].c;
        if (cur == n - 1) break;
    }

    if (cur < n - 1) cout << "IMPOSSIBLE";
    else cout << res;

    return 0;
}
