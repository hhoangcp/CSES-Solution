
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int> > Edges;
vector<int> V[100006];
int n, m, num[100006], lab[100006];
bool odd[100006];

void DFS(int u) {
    num[u] = ++num[0];

    for(int v: V[u])
    if (lab[u] != v) {
        if (num[v] == 0) {
            lab[v] = u;
            DFS(v);

            if (odd[v]) {
                Edges.push_back({v, u});
                odd[v] = false;
            } else {
                Edges.push_back({u, v});
                odd[u] ^= true;
            }
        } else if (num[u] > num[v]) {
            Edges.push_back({u, v});
            odd[u] ^= 1;
        }
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

    for(int u = 1; u <= n; ++u)
    if (num[u] == 0) DFS(u);

    if (count(odd+1, odd+n+1, true)) return cout << "IMPOSSIBLE", 0;
    for(pair<int, int> e: Edges) cout << e.first << ' ' << e.second << '\n';

    return 0;
}
