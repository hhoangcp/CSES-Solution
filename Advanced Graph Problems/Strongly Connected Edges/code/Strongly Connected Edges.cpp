
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int> > Edges;
vector<pair<int, int> > V[100006];
int n, m, low[100006], num[100006], lab[100006];
bool visited[100006], tick[200006];

void DFS(int u) {
    low[u] = num[u] = ++num[0];
    visited[u] = true;

    for(pair<int, int> v: V[u])
    if (lab[u] != v.first) {
        if (!tick[v.second]) {
            Edges.push_back({u, v.first});
            tick[v.second] = true;
        }

        if (visited[v.first]) low[u] = min(low[u], num[v.first]);
        else {
            lab[v.first] = u;
            DFS(v.first);
            low[u] = min(low[u], low[v.first]);

            if (low[v.first] > num[u]) {
                cout << "IMPOSSIBLE";
                exit(0);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;

        V[u].push_back({v, i});
        V[v].push_back({u, i});
    }

    DFS(1);

    if (count(visited+1, visited+n+1, false) != 0) return cout << "IMPOSSIBLE", 0;
    else for(pair<int, int> e: Edges) cout << e.first << ' ' << e.second << '\n';

    return 0;
}
