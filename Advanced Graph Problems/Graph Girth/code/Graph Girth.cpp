
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> V[2506];
int n, m, ans = 1e9, lab[2506], dist[2506];
bool visited[2506];

void BFS(int s) {
    for(int u = 1; u <= n; ++u) dist[u] = 1e9, lab[u] = 0, visited[u] = false;

    queue<int> Q; Q.push(s); dist[s] = 0; visited[s] = true;

    while (!Q.empty()) {
        int u = Q.front(); Q.pop();

        for(int v: V[u])
        if (!visited[v]) {
            visited[v] = true;
            dist[v] = dist[u] + 1;
            lab[v] = u;
            Q.push(v);
        } else if (lab[u] != v && lab[v] != u) ans = min(ans, dist[u] + dist[v] + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        V[u].push_back(v);
        V[v].push_back(u);
    }

    for(int s = 1; s <= n; ++s)
        BFS(s);

    if (ans <= n) cout << ans;
    else cout << -1;

    return 0;
}
