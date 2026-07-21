
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> V[100006], Path;
int n, m, in[100006], out[100006];

void DFS(int u) {
    while (!V[u].empty()) {
        int v = V[u].back(); V[u].pop_back();
        DFS(v);
    }

    Path.push_back(u);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        V[u].push_back(v);
        ++out[u], ++in[v];
    }

    int s, t, I = 0, O = 0, cnt = 0;
    for(int u = 1; u <= n; ++u) {
        if (in[u] == out[u]) ++cnt;
        if (in[u] - out[u] == 1) {t = u, ++I;}
        if (out[u] - in[u] == 1) {s = u, ++O;}
    }

    if (s != 1 || t != n || cnt != n - 2 || I != 1 || O != 1) cout << "IMPOSSIBLE";
    else {
        DFS(1);

        if ((int) Path.size() != m + 1) {
            cout << "IMPOSSIBLE";
            return 0;
        }

        reverse(Path.begin(), Path.end());
        for(int u: Path) cout << u << ' ';
    }

    return 0;
}
