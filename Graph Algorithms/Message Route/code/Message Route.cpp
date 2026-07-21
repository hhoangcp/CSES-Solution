
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> V[100006];
int n, m, t, s, dist[100006], trace[100006];
bool visited[100006];

void BFS() {
    queue<int> Q; Q.push(s); visited[s] = true; dist[s] = 1;

    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        if (u == t) break;

        for(int v: V[u])
        if (!visited[v]) {
            visited[v] = true;
            dist[v] = dist[u] + 1;
            trace[v] = u;

            Q.push(v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> m; s = n, t = 1;
    while (m--) {
        int u, v; cin >> u >> v;
        V[u].push_back(v);
        V[v].push_back(u);
    }

    BFS();

    if (!visited[t]) cout << "IMPOSSIBLE";
    else {
        cout << dist[t] << '\n';

        while (t != s) {
            cout << t << ' ';
            t = trace[t];
        }

        cout << s;
    }

    return 0;
}
