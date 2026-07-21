
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#define llong long long

using namespace std;

llong ans = 0;
vector<int> V[200006];
int n, a, b, lab[200006];

int Prefix(const deque<int> &p, int t) {
    if (t < 0) return 0;
    if (t + 1 >= (int) p.size()) return p[0];
    return p[0] - p[t+1];
}

void Merging(deque<int> &res, deque<int> &up) {
    if (res.size() < up.size()) swap(res, up);

    for(int i = 0; i < (int) up.size() - 1; ++i) up[i] -= up[i+1];
    for(int i = 0; i < (int) up.size(); ++i) ans += 1LL * up[i] * (Prefix(res, b - i) - Prefix(res, a - i - 1));
    for(int i = up.size() - 2; i >= 0; --i) up[i] += up[i+1];
    for(int i = 0; i < (int) up.size(); ++i) res[i] += up[i];
}

deque<int> DFS(int u = 1) {
    deque<int> res(1, 1);

    for(int v: V[u])
    if (lab[u] != v) {
        lab[v] = u;

        deque<int> up = DFS(v);
        up.push_front(up.front());
        Merging(res, up);
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> a >> b;
    for(int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        V[u].push_back(v);
        V[v].push_back(u);
    }

    DFS();
    cout << ans;

    return 0;
}
