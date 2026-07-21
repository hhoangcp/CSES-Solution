
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> V[100006], S;
int n, m, lab[100006], Sconnect = 0;
int low[100006], num[100006];
bool tick[100006];

void DFS(int u) {
    low[u] = 1e9, num[u] = ++num[0];
    S.push_back(u);

    for(int v: V[u])
    if (!tick[v]) {
        if (num[v] > 0) low[u] = min(low[u], num[v]);
        else {
            DFS(v);
            low[u] = min(low[u], low[v]);
        }
    }

    if (low[u] >= num[u]) {
        ++Sconnect;

        do {
            int v = S.back(); S.pop_back();
            lab[v] = Sconnect;
            tick[v] = true;
            if (v == u) break;
        } while (!S.empty());
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        V[u].push_back(v);
    }

    for(int u = 1; u <= n; ++u)
    if (!tick[u]) DFS(u);

    cout << Sconnect << '\n';
    for(int u = 1; u <= n; ++u) cout << lab[u] << ' ';

    return 0;
}
