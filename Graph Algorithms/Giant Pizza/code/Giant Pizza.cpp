
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#define file_name "1684"

using namespace std;

vector<int> V[200006], V_inv[200006], S;
int n, m, n_scc, scc[200006];
char inp[2], ans[100006];
bool visited[200006], visited_inv[200006];

void DFS_1(int u) {
    visited[u] = true;

    for(int v: V[u])
    if (!visited[v]) DFS_1(v);

    S.push_back(u);
}

void DFS_2(int u) {
    visited_inv[u] = true;
    scc[u] = n_scc;

    for(int v: V_inv[u])
    if (!visited_inv[v]) DFS_2(v);
}

void Add_edge(int u, int v) {
    V[u].push_back(v);
    V_inv[v].push_back(u);
}

int main() {
    ///freopen(file_name".inp", "r", stdin);

    scanf("%d%d", &m, &n);
    for(int i=1; i<=m; ++i) {
        int u, v;

        scanf("%s%d", inp+1, &u);
        if (inp[1] == '-') u = -u;

        scanf("%s%d", inp+1, &v);
        if (inp[1] == '-') v = -v;

        if (u > 0) {
            if (v > 0) {
                Add_edge(u+n, v);
                Add_edge(v+n, u);
            } else {
                Add_edge(u+n, n-v);
                Add_edge(-v, u);
            }
        } else {
            if (v > 0) {
                Add_edge(v+n, n-u);
                Add_edge(-u, v);
            } else {
                Add_edge(-u, n-v);
                Add_edge(-v, n-u);
            }
        }
    }

    for(int u=1; u<=2*n; ++u)
    if (!visited[u]) DFS_1(u);

    while (!S.empty()) {
        int u = S.back(); S.pop_back();

        if (!visited_inv[u]) {
            ++n_scc;
            DFS_2(u);
        }
    }

    for(int u=1; u<=n; ++u)
    if (scc[u] == scc[u+n]) {
        cout << "IMPOSSIBLE";
        return 0;
    } else ans[u] = (scc[u] > scc[u+n]) ? '+' : '-';

    for(int u=1; u<=n; ++u) putchar(ans[u]), putchar(' ');

    return 0;
}
