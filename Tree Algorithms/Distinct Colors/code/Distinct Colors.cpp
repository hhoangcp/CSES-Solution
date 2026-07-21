
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> V[200006], C;
vector<pair<int, int> > L[200006];
int bit[200006], lab[200006], c[200006];
int n, N, Time = 0, Start[200006];
int color[200006], pre[200006], link[200006], ans[200006];
bool tick[200006];

void DFS(int u) {
    Start[u] = ++Time;
    color[Time] = c[u];

    for(int v: V[u]) {
        if (lab[u] == v) continue;
        lab[v] = u;
        DFS(v);
    }

    L[Time].push_back({Start[u], u});
}

void Update(int u, int val) {
    for(; u <= n; u += (u & (-u))) bit[u] += val;
}

int Query(int u) {
    int sum = 0;
    for(; u > 0; u -= (u & (-u))) sum += bit[u];
    return sum;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> c[i];
        C.push_back(c[i]);
    }

    for(int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        V[u].push_back(v);
        V[v].push_back(u);
    }

    sort(C.begin(), C.end());
    C.resize(unique(C.begin(), C.end()) - C.begin());

    N = C.size();
    for(int i = 1; i <= n; ++i) c[i] = lower_bound(C.begin(), C.end(), c[i]) - C.begin() + 1;

    DFS(1);

    for(int i = 1; i <= n; ++i) {
        pre[i] = link[color[i]];
        if (pre[i] == 0) Update(i, 1);
        link[color[i]] = i;
    }

    for(int i = 1; i <= n; ++i) {
        if (pre[i] > 0) {
            Update(pre[i], -1);
            Update(i, 1);
        }

        if (!L[i].empty()) {
            int del = Query(i);
            for(pair<int, int> p: L[i]) ans[p.second] = del - Query(p.first - 1);
        }
    }

    for(int u = 1; u <= n; ++u) cout << ans[u] << ' ';

    return 0;
}
