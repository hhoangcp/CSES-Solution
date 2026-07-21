
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> V[100006], Topo;
int n, m;
bool visited[100006], in[100006];

void DFS(int u) {
    visited[u] = in[u] = true;

    for(int v: V[u])
    if (!visited[v]) DFS(v);
    else if (in[v]) {
        cout << "IMPOSSIBLE";
        exit(0);
    }

    in[u] = false;
    Topo.push_back(u);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> m;
    while (m--) {
        int u, v; cin >> u >> v;
        V[u].push_back(v);
    }

    for(int u = 1; u <= n; ++u)
    if (!visited[u]) DFS(u);

    reverse(Topo.begin(), Topo.end());
    for(int u: Topo) cout << u << ' ';

    return 0;
}
