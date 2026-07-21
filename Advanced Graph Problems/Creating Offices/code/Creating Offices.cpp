
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Data {
    int depth, node;

    bool operator > (const Data &other) const {
        return depth > other.depth;
    }
};

vector<int> V[200006];
int n, d, depth[200006], ans = 0;
bool mask[200006], visited[200006];

Data DFS(int u) {
    visited[u] = true;
    mask[u] = true; ++ans;

    vector<Data> tmp(0, {0, 0}); tmp.push_back({depth[u], u});

    for(int v: V[u]) {
        if (visited[v]) continue;

        depth[v] = depth[u] + 1;
        tmp.push_back(DFS(v));
    }

    sort(tmp.begin(), tmp.end(), greater<Data>());

    while ((int) tmp.size() >= 2 && tmp[tmp.size() - 1].depth + tmp[tmp.size() - 2].depth - 2 * depth[u] < d) {
        --ans; mask[tmp.back().node] = false;
        tmp.pop_back();
    }

    return tmp.back();
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> d;
    for(int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        V[u].push_back(v);
        V[v].push_back(u);
    }

    DFS(1);

    cout << ans << '\n';
    for(int u = 1; u <= n; ++u)
    if (mask[u]) cout << u << ' ';

    return 0;
}
