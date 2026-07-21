
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct TEdge {
    int v, idx;
};

vector<TEdge> V[100006];
vector<int> S, Path;
int start[100006], n, m;
bool deleted[400006];

void Euler() {
    S.push_back(1);

    do {
        int u = S.back();
        for(int &i=start[u]; i<(int) V[u].size() && deleted[V[u][i].idx]; ++i);
        if (start[u] < (int) V[u].size()) {
            S.push_back(V[u][start[u]].v);
            deleted[V[u][start[u]].idx] = true;
        } else {
            Path.push_back(u);
            S.pop_back();
        }
    } while (!S.empty());

    if ((int) Path.size() != m + 1) cout << "IMPOSSIBLE";
    else for(int u: Path) cout << u << ' ';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> m;
    for(int i=1; i<=m; ++i) {
        int u, v; cin >> u >> v;
        V[u].push_back({v, i});
        V[v].push_back({u, i});
    }

    for(int u = 1; u <= n; ++u)
    if (V[u].size() & 1) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    Euler();

    return 0;
}
