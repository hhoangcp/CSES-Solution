
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> V[26];
const int mod = 1e9+7;
int dp[(1<<20)+6][26], n, m;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> m;
    dp[1][0] = 1;
    for(int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v; --u, --v;
        V[u].push_back(v);
    }

    for(int i = 1; i < (1 << (n-1)); i += 2) {
        for(int u = 0; u < n; ++u)
        if (i & (1 << u))
            for(int v: V[u])
            if (!(i & (1 << v))) {
                int V = i | (1 << v);

                (dp[V][v] += dp[i][u]) %= mod;
            }
    }

    cout << dp[(1 << n) - 1][n - 1];

    return 0;
}
