
#include <iostream>
#include <algorithm>
#include <vector>
#define mk make_pair

using namespace std;

vector<int> V[100006], S, V_scc[100006], V_neg_scc[100006];
int n, m, low[100006], num[100006], scc[100006], top_scc[100006];
int num_scc;

void Tarjan(int u) {
    low[u] = 1e9, num[u] = ++num[0];
    S.push_back(u);

    for(int v: V[u]) {
        if (num[v] > 0) low[u] = min(low[u], num[v]);
        else {
            Tarjan(v);
            low[u] = min(low[u], low[v]);
        }
    }

    if (low[u] >= num[u]) {
        int v; ++num_scc; top_scc[num_scc] = u;
        do {
            v = S.back(); S.pop_back();
            num[v] = low[v] = 1e9;
            scc[v] = num_scc;
        } while (v != u);
    }
}

bool avail[100006];
int degIn[100006], degOut[100006];
vector<int> In, Out;

void DFS_In(int u) {
    avail[u] = true;
    if (degIn[u] == 0) In.push_back(u);
    for(int v: V_scc[u])
    if (!avail[v]) DFS_In(v);
}

void DFS_Out(int u) {
    avail[u] = true;
    if (degOut[u] == 0) Out.push_back(u);
    for(int v: V_neg_scc[u])
    if (!avail[v]) DFS_Out(v);
}

void init() {
    for(int u=1; u <= n; ++u)
    for(int v: V[u])
    if (scc[u] != scc[v]) {
        ++degIn[scc[v]];
        ++degOut[scc[u]];
        V_scc[scc[v]].push_back(scc[u]);
    }
}

vector<pair<int, int> > Edges;

void add_edge(int u, int v, int type) {
    ++degIn[v], ++degOut[u];
    Edges.push_back({top_scc[u], top_scc[v]});
    if (type == 0) V_scc[v].push_back(u);
    else V_neg_scc[u].push_back(v);
}

void find_edges_added() {
    int pivot_In = 0, pivot_Out = 0;

    for(int u=1; u<=num_scc; ++u)
    if (degOut[u] == 0) {
        int pre_sz = In.size();
        if (!avail[u]) DFS_In(u);
        if (pivot_Out == 0) pivot_Out = u;
        else if ((int) In.size() > pre_sz) {
            int v = In.back();
            add_edge(pivot_Out, v, 0);
            pivot_Out = u;
        }
    }

    for(int u=1; u<=num_scc; ++u) {
        avail[u] = false;
        for(int v: V_scc[u]) V_neg_scc[v].push_back(u);
    }

    for(int v=1; v<=num_scc; ++v)
    if (degIn[v] == 0) {
        int pre_sz = Out.size();
        if (!avail[v]) DFS_Out(v);
        if (pivot_In == 0) pivot_In = v;
        else if ((int) Out.size() > pre_sz) {
            int u = Out.back();
            add_edge(u, pivot_In, 1);
            pivot_In = v;
        }
    }

    add_edge(pivot_Out, pivot_In, 0);
    for(int u=1, v = 0; u <= num_scc; ++u)
    if (degOut[u] == 0) {
        ++v;
        while (v <= num_scc && degIn[v] > 0) ++v;
        if (v <= num_scc) add_edge(u, v, 0);
    }

    for(int ver=1; ver <= num_scc; ++ver) {
        if (degIn[ver] == 0) add_edge(pivot_Out, ver, 0);
        if (degOut[ver] == 0) add_edge(ver, pivot_In, 0);
    }

    cout << Edges.size() << "\n";
    for(pair<int, int> edge: Edges) cout << edge.first << " " << edge.second << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> m;
    for(int i=1; i<=m; ++i) {
        int u, v; cin >> u >> v;
        V[u].push_back(v);
    }

    for(int i=1; i<=n; ++i)
    if (!num[i]) Tarjan(i);

    if(num_scc == 1) return cout << 0, 0;

    init();
    find_edges_added();

    return 0;
}
