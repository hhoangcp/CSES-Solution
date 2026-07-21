#include <iostream>

using namespace std;

char ch[2][1006];
bool used[4];

void solve() {
    int n, m; cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) ch[0][j] = ch[1][j], ch[1][j] = 0;

        for (int j = 0; j < m; ++j) {
            cin >> ch[1][j];

            used[ch[1][j] - 'A'] = true;
            if (i > 0) used[ch[0][j] - 'A'] = true;
            if (j > 0) used[ch[1][j - 1] - 'A'] = true;

            for (int k = 0; k < 4; ++k)
                if (!used[k]) {
                    ch[1][j] = k + 'A';
                    cout << ch[1][j];
                    break;
                }

            for (int k = 0; k < 4; ++k) used[k] = false;
        }

        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int tests = 1; //cin >> tests;
    for (int i = 0; i < tests; ++i) {
        solve();
    }
}