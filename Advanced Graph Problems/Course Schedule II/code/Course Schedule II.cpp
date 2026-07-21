
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

vector<int> V[100006];
priority_queue<int> PQ;
int n, m, out[100006];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        V[v].push_back(u);
        ++out[u];
    }

    for(int u = 1; u <= n; ++u)
    if (!out[u]) PQ.push(u);

    vector<int> Ans;
    for(int i = 1; i <= n; ++i) {
        int u = PQ.top(); PQ.pop();
        Ans.push_back(u);

        for(int v: V[u])
        if (--out[v] == 0) PQ.push(v);
    }

    reverse(Ans.begin(), Ans.end());
    for(int u: Ans) cout << u << ' ';

    return 0;
}
