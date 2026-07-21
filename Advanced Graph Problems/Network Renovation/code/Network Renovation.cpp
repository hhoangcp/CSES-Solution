
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> Leaf, V[100006];
int n, lab[100006];

void DFS(int u) {
    for(int v: V[u])
    if (lab[u] != v) {
        lab[v] = u;
        DFS(v);
    }

    if ((int) V[u].size() == 1) Leaf.push_back(u);
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

    if (Leaf.size() & 1) Leaf.push_back(Leaf[0]);

    cout << (Leaf.size() >> 1) << '\n';
    for(int i = 0; i < (int) (Leaf.size() >> 1); ++i) cout << Leaf[i] << ' ' << Leaf[i + (Leaf.size() >> 1)] << '\n';

    return 0;
}
