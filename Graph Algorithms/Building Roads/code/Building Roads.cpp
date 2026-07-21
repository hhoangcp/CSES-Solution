
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> V[100006];
int n, m, lab[100006], connect = 0;
bool visited[100006];

void DFS(int u) {
    visited[u] = true;

    for(int v: V[u])
    if (!visited[v]) DFS(v);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> m;
    while (m--) {
        int u, v; cin >> u >> v;
        V[u].push_back(v);
        V[v].push_back(u);
    }

    for(int u = 1; u <= n; ++u)
    if (!visited[u]) {
        ++connect; lab[connect] = u;
        DFS(u);
    }

    cout << connect - 1 << '\n';
    for(int i = 2; i <= connect; ++i) cout << lab[i-1] << ' ' << lab[i] << '\n';

    return 0;
}
