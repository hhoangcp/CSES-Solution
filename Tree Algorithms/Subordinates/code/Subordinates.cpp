
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> V[200006];
int n, sz[200006];

void DFS(int u) {
    sz[u] = 1;

    for(int v: V[u]) {
        DFS(v);
        sz[u] += sz[v];
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;
    for(int i = 2; i <= n; ++i) {
        int u; cin >> u;
        V[u].push_back(i);
    }

    DFS(1);
    for(int i = 1; i <= n; ++i) cout << sz[i] - 1 << ' ';

    return 0;
}
