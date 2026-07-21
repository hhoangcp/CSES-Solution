
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> V[100006], RV[100006], S;
int n, m, In[100006], ans = 0;
bool visited[100006];

void DFS(int u) {
    visited[u] = true;
    S.push_back(u);
    ++ans;

    for(int v: V[u])
    if (!visited[v]) DFS(v);

    for(int v: RV[u])
    if (!visited[v]) DFS(v);
}

bool check_DAG() {
    queue<int> Q;
    for(int u: S)
    if (!In[u]) Q.push(u);

    int cnt = 0;
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        ++cnt;

        for(int v: V[u])
        if (--In[v] == 0) Q.push(v);
    }

    return cnt == (int) S.size();
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        V[u].push_back(v);
        RV[v].push_back(u);
        ++In[v];
    }

    for(int u = 1; u <= n; ++u)
    if (!visited[u]) {
        S.clear();
        DFS(u);

        if (check_DAG()) --ans;
    }

    cout << ans;
    return 0;
}
