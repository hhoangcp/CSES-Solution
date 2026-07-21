
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> V[200006];
int n, sz[200006], lab[200006];

void DFS(int u) {
    sz[u] = 1;
    for(int v : V[u])
    if (lab[u] != v) {
        lab[v] = u;

        DFS(v);
        sz[u] += sz[v];
    }
}

int Find_Centroid(int u) {
    for(int v : V[u])
    if (lab[u] != v && sz[v] * 2 > n) return Find_Centroid(v);

    return u;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;
    for(int i=1; i<n; ++i) {
        int u, v; cin >> u >> v;

        V[u].push_back(v);
        V[v].push_back(u);
    }

    DFS(1);
    cout << Find_Centroid(1);

    return 0;
}
