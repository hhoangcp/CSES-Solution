
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct TEdge {
    int u, v;
} E[200006], Q[200006];

int Par[200006], Sz[200006], ans[200006];
int n, m, q, Left[200006], Right[200006];
vector<int> Binary_Search[200006];

int Find(int u) {
    if (Par[u] != u) Par[u] = Find(Par[u]);
    return Par[u];
}

void Union(int u, int v) {
    u = Find(u), v = Find(v);
    if (u == v) return;

    if (Sz[u] < Sz[v]) swap(u, v);
    Sz[u] += Sz[v]; Par[v] = u;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> m >> q;
    for(int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        E[i] = {u, v};
    }

    for(int i = 1; i <= q; ++i) {
        int u, v; cin >> u >> v;
        Q[i] = {u, v};

        if (u == v) {
            ans[i] = 0;
            continue;
        }

        ans[i] = -1;
        Left[i] = 1, Right[i] = m;
    }

    while (true) {
        bool stop = true;

        for(int i = 1; i <= m; ++i) Binary_Search[i].clear();

        for(int i = 1; i <= q; ++i)
        if (ans[i] != 0 && Left[i] <= Right[i]) {
            stop = false;

            int mid = (Left[i] + Right[i]) >> 1;
            Binary_Search[mid].push_back(i);
        }

        if (stop) break;

        for(int u = 1; u <= n; ++u) Par[u] = u, Sz[u] = 1;
        for(int i = 1; i <= m; ++i) {
            Union(E[i].u, E[i].v);

            for(int idx: Binary_Search[i])
            if (Find(Q[idx].u) == Find(Q[idx].v)) {
                ans[idx] = i;
                Right[idx] = i - 1;
            } else Left[idx] = i + 1;
        }
    }

    for(int i = 1; i <= q; ++i) cout << ans[i] << '\n';

    return 0;
}
