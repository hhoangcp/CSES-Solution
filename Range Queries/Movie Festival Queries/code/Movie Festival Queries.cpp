
#include <iostream>
#include <algorithm>

using namespace std;

int binary_lifting[1000006][22];
int n, m;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        int s, t; cin >> s >> t;
        binary_lifting[t][0] = max(binary_lifting[t][0], s);
    }

    for(int i = 1; i <= 1000000; ++i)
        binary_lifting[i][0] = max(binary_lifting[i][0], binary_lifting[i-1][0]);

    for(int i = 1; i <= 20; ++i)
    for(int j = 1; j <= 1000000; ++j)
        binary_lifting[j][i] = binary_lifting[binary_lifting[j][i-1]][i-1];

    while (m--) {
        int s, t; cin >> s >> t;

        int res = 0;
        while (t > 0) {
            int p = 0;

            for(; p <= 20; ++p)
            if (binary_lifting[t][p] < s) break;

            if (p == 0) break;

            res += (1 << (p-1));
            t = binary_lifting[t][p-1];
        }

        cout << res << '\n';
    }

    return 0;
}
