/// DSU with Rollback

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define llong long long

using namespace std;

typedef pair<int, int> Data;
vector<Data> Queries[400016], DSU_save;
int Par[100006], Sz[100006], n, m, q, cgs = 0;

void Init() {
    DSU_save.clear();
    for(int u = 1; u <= n; ++u) Par[u] = u, Sz[u] = 1;
}

int Find(int u) {
    if (Par[u] != u) return Find(Par[u]);
    return u;
}

void Union(int u, int v) {
    u = Find(u), v = Find(v);
    if (u == v) {
        DSU_save.push_back({0, 0});
        return;
    }

    if (Sz[u] < Sz[v]) swap(u, v);
    Par[v] = u; Sz[u] += Sz[v];
    --cgs;
    DSU_save.push_back({u, v});
}

void RollBack() {
    Data e = DSU_save.back(); DSU_save.pop_back();
    if (e == make_pair(0, 0)) return;

    int u = e.first, v = e.second;
    Sz[u] -= Sz[v]; Par[v] = v; ++cgs;
}

void Add(int id, int l, int r, int u, int v, Data p) {
    if (l > v || u > r) return;
    if (u <= l && r <= v) {
        Queries[id].push_back(p);
        return;
    }

    int mid = (l + r) >> 1;
    Add(id*2+1, l, mid, u, v, p);
    Add(id*2+2, mid+1, r, u, v, p);
}

int ans[100006];

void Query_All(int id, int l, int r) {
    if (l > r) return;
    for(Data e: Queries[id]) Union(e.first, e.second);
    if (l == r) ans[l] = cgs;
    else {
        int mid = (l + r) >> 1;
        Query_All(id*2+1, l, mid);
        Query_All(id*2+2, mid+1, r);
    }

    for(int i = 0; i < (int) Queries[id].size(); ++i) RollBack();
}

map<Data, int> Start;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> m >> q; Init();
    while(m--) {
        int u, v; cin >> u >> v;
        if (u > v) swap(u, v);
        Start.insert({{u, v}, 0});
    }

    for(int i = 1; i <= q; ++i) {
        int type, u, v; cin >> type >> u >> v;
        if (u > v) swap(u, v);

        if (type == 1) Start.insert({{u, v}, i});
        else {
            Add(0, 0, q, Start[{u, v}], i-1, {u, v});
            Start.erase(Start.find({u, v}));
        }
    }

    for(auto D: Start) Add(0, 0, q, D.second, q, D.first);

    cgs = n;
    Query_All(0, 0, q);
    for(int i = 0; i <= q; ++i) cout << ans[i] << ' ';

    return 0;
}
