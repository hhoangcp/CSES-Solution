
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;

        if (n / k + ((n % k) ? 1: 0) > k) {
            cout << "IMPOSSIBLE\n";
            continue;
        }

        for(int i = k; i <= n + k - 1; i += k)
        for(int j = i; j >= i - k + 1; --j)
            if (j <= n) cout << j << ' ';

        cout << '\n';
    }

    return 0;
}
