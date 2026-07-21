
#include <iostream>
#include <algorithm>

using namespace std;

int binary_lifting[200006][36], n, q, len[200006];
bool visited[200006];

void DFS(int u) {
    if (visited[u]) return;
    visited[u] = true;

    DFS(binary_lifting[u][0]);
    len[u] = len[binary_lifting[u][0]] + 1;
}

int Lifting(int u, int k) {
    if (k <= 0) return u;

    for(int i = 18; i >= 0; --i)
    if (k & (1 << i)) u = binary_lifting[u][i];

    return u;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> q;
    for(int i = 1; i <= n; ++i) cin >> binary_lifting[i][0];

    for(int i = 1; i <= 18; ++i)
    for(int j = 1; j <= n; ++j) binary_lifting[j][i] = binary_lifting[binary_lifting[j][i-1]][i-1];

    for(int u = 1; u <= n; ++u)
    if (!visited[u]) DFS(u);

    while (q--) {
        int u, v; cin >> u >> v;
        int x = Lifting(u, len[u]);

        if (Lifting(u, len[u] - len[v]) == v) cout << len[u] - len[v] << '\n';
        else if (Lifting(x, len[x] - len[v]) == v) cout << len[u] + len[x] - len[v] << '\n';
        else cout << -1 << '\n';
    }

    return 0;
}
