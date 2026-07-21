
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <functional>

using namespace std;

typedef vector<int> vec;

vec Find_Centroid(int n, vec V[]) {
    vec sz(n+1, 0);

    function<void (int, int)> DFS = [&] (int u, int pre) {
        sz[u] = 1;

        for(int v: V[u])
        if (v != pre) {
            DFS(v, u);
            sz[u] += sz[v];
        }
    };

    DFS(1, -1);
    vec Centroids;

    function<void (int, int)> Find = [&] (int u, int pre) {
        bool is_centroid = true;

        for(int v: V[u])
        if (v != pre) {
            Find(v, u);
            if (sz[v] * 2 > n) is_centroid = false;
        }

        if (n - sz[u] > n / 2) is_centroid = false;
        if (is_centroid) Centroids.push_back(u);
    };

    Find(1, -1);

    return Centroids;
}

vec V1[100006], V2[100006];
map<vec, int> M;
int n, cnt = 0;

int DFS(int u, int par, vec V[]) {
    vec tmp(0, 0);

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
        M.clear(); cnt = 0;

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

        vec c1 = Find_Centroid(n, V1), c2 = Find_Centroid(n, V2);
        if (c1.size() != c2.size()) {
            cout << "NO\n";
            continue;
        }

        bool ok = false;
        int T1 = DFS(c1[0], -1, V1);
        for(int c: c2) {
            int T2 = DFS(c, -1, V2);

            if (T2 == T1) {
                ok = true;
                break;
            }
        }

        if (ok) cout << "YES\n"; else cout << "NO\n";
    }

    return 0;
}
