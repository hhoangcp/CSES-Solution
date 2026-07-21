#include <iostream>
#include <algorithm>
#include <vector>
#define llong long long

using namespace std;

llong bit[200006];
vector<int> V[200006];
int Start[200006], End[200006], Time = 0;
int n, q, w[200006], lab[200006];

void Update(int u, int val) {
    for(; u <= n; u += (u & (-u))) bit[u] += val;
}

llong Query(int u) {
    llong sum = 0;
    for(; u > 0; u -= (u & (-u))) sum += bit[u];
    return sum;
}

void DFS(int u) {
    Start[u] = ++Time;

    for(int v: V[u])
    if (lab[u] != v) {
        lab[v] = u;
        DFS(v);
    }

    End[u] = Time;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> q;
    for(int i = 1; i <= n; ++i) cin >> w[i];
    for(int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        V[u].push_back(v);
        V[v].push_back(u);
    }

    DFS(1);
    for(int u = 1; u <= n; ++u) Update(Start[u], w[u]);

    while (q--) {
        int type; cin >> type;

        if (type == 1) {
            int u, x; cin >> u >> x;
            Update(Start[u], x - w[u]); w[u] = x;
        } else {
            int u; cin >> u;
            cout << Query(End[u]) - Query(Start[u] - 1) << '\n';
        }
    }

    return 0;
}
