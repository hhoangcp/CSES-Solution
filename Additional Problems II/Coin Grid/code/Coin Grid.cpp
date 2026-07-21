
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;

struct TEdge {
    int u, v, cap, flow;
} E[30006];

set<int> V2[206];
int n, m = 0, link[30006], head[206], ptr[206], d[206];

void Add_edge(int u, int v, int cap) {
    E[m] = {u, v, cap, 0};
    link[m] = head[u]; head[u] = m++;

    E[m] = {v, u, 0, 0};
    link[m] = head[v]; head[v] = m++;
}

bool BFS(int s, int t) {
    for(int i = 0; i <= 2*n+1; ++i) d[i] = 1e9;

    queue<int> Q; Q.push(s); d[s] = 0;
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();

        for(int i = head[u]; i > -1; i = link[i]) {
            int v = E[i].v;

            if (E[i].cap - E[i].flow >= 1 && d[v] == 1e9) {
                d[v] = d[u] + 1;
                Q.push(v);
            }
        }
    }

    return d[t] < 1e9;
}

bool DFS(int u, int t) {
    if (u == t) return true;

    for(int &i = ptr[u]; i > -1; i = link[i]) {
        int v = E[i].v, cap = E[i].cap, &flow = E[i].flow;
        if (d[v] == d[u] + 1 && cap - flow >= 1 && DFS(v, t)) {
            ++flow;
            --E[i^1].flow;
            return true;
        }
    }

    return false;
}

int Dinic(int s, int t) {
    int max_flow = 0;

    while (BFS(s, t)) {
        for(int i = 0; i <= 2*n+1; ++i) ptr[i] = head[i];
        while (DFS(s, t)) ++max_flow;
    }

    return max_flow;
}

bool visited[206];

void DFS(int u) {
    visited[u] = true;

    for(int v: V2[u])
    if (!visited[v]) DFS(v);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;
    fill(head, head+2*n+2, -1);

    for(int i = 1; i <= n; ++i)
    for(int j = n+1; j <= 2*n; ++j) {
        char c; cin >> c;

        if (c == 'o') {
            Add_edge(i, j, 1);
            V2[i].insert(j);
        }
    }

    for(int i = 1; i <= n; ++i) {
        Add_edge(0, i, 1);
        Add_edge(i+n, 2*n+1, 1);
    }

    cout << Dinic(0, 2*n+1) << '\n';

    vector<int> S;
    for(int u = 1; u <= n; ++u) {
        S.push_back(u);

        for(int i = head[u]; i > -1; i = link[i])
        if (E[i].cap == 1 && E[i].flow == 1 && E[i].v > n) {
            V2[E[i].v].insert(u);
            V2[u].erase(E[i].v);
            S.pop_back();
            break;
        }
    }

    for(int u: S)
    if (!visited[u]) DFS(u);

    for(int u = 1; u <= n; ++u) {
        if (!visited[u]) cout << "1 " << u << '\n';
        if (visited[u+n]) cout << "2 " << u << '\n';
    }

    return 0;
}
