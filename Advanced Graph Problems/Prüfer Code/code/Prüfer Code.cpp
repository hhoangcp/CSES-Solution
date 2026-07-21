
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, deg[200006], prufer[200006];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n - 2; ++i) {
        cin >> prufer[i];
        ++deg[prufer[i]];
    }

    for(int u = 1; u <= n; ++u) ++deg[u];

    int cur = 1;
    while (cur <= n && deg[cur] != 1) ++cur;

    int leaf = cur;
    for(int i = 1; i <= n - 2; ++i) {
        cout << leaf << ' ' << prufer[i] << '\n';

        if (--deg[prufer[i]] == 1 && prufer[i] < cur) leaf = prufer[i];
        else {
            ++cur;
            while (cur <= n && deg[cur] != 1) ++cur;
            leaf = cur;
        }
    }

    cout << leaf << ' ' << n;

    return 0;
}
