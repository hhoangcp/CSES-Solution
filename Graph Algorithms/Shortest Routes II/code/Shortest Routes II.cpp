
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

int n, m, q;
llong floyd[506][506];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> m >> q;

    for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= n; ++j) {
        if (i == j) floyd[i][j] = 0;
        else floyd[i][j] = 2e18;
    }

    for(int i = 1; i <= m; ++i) {
        int u, v, c; cin >> u >> v >> c;
        floyd[u][v] = floyd[v][u] = min(floyd[u][v], 1LL * c);
    }

    for(int m = 1; m <= n; ++m)
    for(int i = 1; i <= n; ++i)
    if (floyd[i][m] < 2e18)
        for(int j = 1; j <= n; ++j)
        if (floyd[m][j] < 2e18) floyd[i][j] = min(floyd[i][j], floyd[i][m] + floyd[m][j]);

    while (q--) {
        int u, v; cin >> u >> v;
        if (floyd[u][v] < 2e18) cout << floyd[u][v] << '\n';
        else cout << "-1\n";
    }

    return 0;
}
