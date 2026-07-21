
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> V[200006];
int n, q, par[200006][20];

void DFS(int u) {
    for(int i = 1; i <= 18; ++i) par[u][i] = par[par[u][i-1]][i-1];

    for(int v: V[u])
    if (par[u][0] != v) {
        par[v][0] = u;
        DFS(v);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> q;
    for(int v = 2; v <= n; ++v) {
        int u; cin >> u;
        V[u].push_back(v);
    }

    DFS(1);

    while(q--) {
        int u, k; cin >> u >> k;

        int ans = u;
        for(int i = 18; i >= 0; --i)
        if (k & (1 << i)) ans = par[ans][i];

        if (ans == 0) ans = -1;
        cout << ans << '\n';
    }

    return 0;
}
