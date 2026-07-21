
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> V[100006], S, cycle;
int color[100006], n, m;

bool DFS(int u) {
    color[u] = 1;
    S.push_back(u);

    for(int v: V[u]) {

        if (color[v] == 0) {
            if (DFS(v)) return true;
        } else if (color[v] == 1) {
            cycle.push_back(v);

            while (S.back() != v) {
                cycle.push_back(S.back());
                S.pop_back();
            }

            cycle.push_back(v);
            reverse(cycle.begin(), cycle.end());
            return true;
        }
    }

    color[u] = 2;
    S.pop_back();
    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> m;
    while (m--) {
        int u, v; cin >> u >> v;
        V[u].push_back(v);
    }

    for(int u = 1; u <= n; ++u)
    if (color[u] == 0 && DFS(u)) {
        cout << cycle.size() << '\n';
        for(int v: cycle) cout << v << ' ';

        return 0;
    }

    cout << "IMPOSSIBLE";

    return 0;
}
