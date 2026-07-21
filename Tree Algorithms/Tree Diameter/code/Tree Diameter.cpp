
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> V[200006];
int s, ans, n, depth[200006], lab[200006];

void DFS(int u) {
    for(int v: V[u])
    if (lab[u] != v) {
        lab[v] = u; depth[v] = depth[u] + 1;
        DFS(v);

        if (ans < depth[v]) {
            ans = depth[v];
            s = v;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;
    for(int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        V[u].push_back(v);
        V[v].push_back(u);
    }

    DFS(1);

    for(int u = 1; u <= n; ++u) depth[u] = lab[u] = 0;
    DFS(s);

    cout << ans;

    return 0;
}
