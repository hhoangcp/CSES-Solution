
#include <iostream>
#include <algorithm>
#include <queue>
#define llong long long

using namespace std;

struct Data {
    int v, c;
};

vector<Data> V[2506];
vector<int> V_inv[2506];
llong dist[2506], mmax = 0;
int n, m, cnt[2506];
bool in[2506], visited[2506];

bool Find_Maximum(int s = 1, int t = n) {
    for(int i = 1; i <= n; ++i) dist[i] = 2e18;

    queue<int> Q; Q.push(s); in[s] = true;
    dist[s] = 0;

    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        in[u] = false;

        for(Data v: V[u])
        if (visited[v.v] && dist[v.v] > dist[u] + v.c) {
            dist[v.v] = dist[u] + v.c;

            if (!in[v.v]) {
                in[v.v] = true;
                Q.push(v.v);
                ++cnt[v.v];

                if (cnt[v.v] > n) return false;
            }
        }
    }

    mmax = -dist[t];
    return true;
}

void DFS(int u) {
    visited[u] = true;

    for(int v: V_inv[u])
    if (!visited[v]) DFS(v);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int u, v, c; cin >> u >> v >> c; c = -c;

        V[u].push_back({v, c});
        V_inv[v].push_back(u);
    }

    DFS(n);
    if (Find_Maximum()) cout << mmax; else cout << -1;

    return 0;
}
