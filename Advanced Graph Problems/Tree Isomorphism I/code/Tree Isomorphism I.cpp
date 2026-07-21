
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

vector<int> V1[100006], V2[100006];
map<vector<int>, int> M;
int n, cnt = 0;

int DFS(int u, int par, vector<int> V[]) {
    vector<int> tmp(0, 0);

    for(int v: V[u])
    if (v != par) tmp.push_back(DFS(v, u, V));

    sort(tmp.begin(), tmp.end());

    if (!M.count(tmp)) M.insert({tmp, ++cnt});
    return M[tmp];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n;
        M.clear();

        cin >> n;
        for(int i = 1; i <= n; ++i) V1[i].clear();
        for(int i = 1; i < n; ++i) {
            int u, v; cin >> u >> v;
            V1[u].push_back(v);
            V1[v].push_back(u);
        }

        for(int i = 1; i <= n; ++i) V2[i].clear();
        for(int i = 1; i < n; ++i) {
            int u, v; cin >> u >> v;
            V2[u].push_back(v);
            V2[v].push_back(u);
        }

        int T1 = DFS(1, 0, V1);
        int T2 = DFS(1, 0, V2);

        if (T1 == T2) cout << "YES\n"; else cout << "NO\n";
    }

    return 0;
}
