
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        if (u > v) swap(u, v);
        cout << u << ' ' << v << '\n';
    }

    return 0;
}
