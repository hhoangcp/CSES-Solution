
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> V[100006], S;
int n, m, trace[100006], s;
bool visited[100006], in[100006];

void DFS(int u, int pre) {
    visited[u] = in[u] = true;
    S.push_back(u);

    for(int v: V[u])
    if (v != pre) {
        if (!visited[v]) DFS(v, u);
        else if ((int) S.size() > 1 && in[v] && S.back() != v && S[S.size() - 2] != v) {
            vector<int> Path; Path.push_back(v);
            while (S.back() != v) {
                Path.push_back(S.back());
                S.pop_back();
            }
            Path.push_back(v);

            cout << Path.size() << '\n';
            for(int ver: Path) cout << ver << ' ';
            exit(0);
        }
    }

    in[u] = false;
    S.pop_back();
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
    if (!visited[u]) DFS(u, 0);

    cout << "IMPOSSIBLE";

    return 0;
}
