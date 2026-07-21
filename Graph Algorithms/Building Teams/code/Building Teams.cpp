
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> V[100006];
int n, m, color[100006];

bool BFS(int s) {
    queue<int> Q; Q.push(s); color[s] = 1;

    while (!Q.empty()) {
        int u = Q.front(); Q.pop();

        for(int v: V[u])
        if (color[v] == 0) {
            color[v] = 3 - color[u];
            Q.push(v);
        } else if (color[v] == color[u]) return false;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> m;
    for(int i = 1; i <= n; ++i) color[i] = 0;
    while (m--) {
        int u, v; cin >> u >> v;
        V[u].push_back(v);
        V[v].push_back(u);
    }

    for(int u = 1; u <= n; ++u)
    if (color[u] == 0) {
        if (!BFS(u)) {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }

    for(int u = 1; u <= n; ++u) cout << color[u] << ' ';

    return 0;
}
