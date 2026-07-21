
#include <iostream>
#include <algorithm>

using namespace std;

int binary_lifting[200006][31], n, q;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> q;
    for(int i = 1; i <= n; ++i) cin >> binary_lifting[i][0];

    for(int i = 1; i <= 30; ++i)
    for(int j = 1; j <= n; ++j) binary_lifting[j][i] = binary_lifting[binary_lifting[j][i-1]][i-1];

    while (q--) {
        int u, k; cin >> u >> k;

        for(int i = 30; i >= 0; --i)
        if (k & (1 << i)) u = binary_lifting[u][i];

        cout << u << '\n';
    }

    return 0;
}
