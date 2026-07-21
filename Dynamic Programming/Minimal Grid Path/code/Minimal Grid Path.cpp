#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#define ll long long
#define ull unsigned long long

using namespace std;

vector<pair<int, int>> P[6007];
char a[3006][3006];
bool used[3006][3006];

void solve() {
    int n; cin >> n;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            P[i + j].push_back({i, j});
        }

    for (int k = 0; k < 2 * n - 1; ++k) {
        char ans = 'Z' + 1;

        for (pair<int, int> p : P[k]) {
            int i = p.first, j = p.second;

            if (i == 0 && j == 0) {
                ans = min(ans, a[i][j]);
            } else {
                if (i > 0 && used[i - 1][j]) ans = min(ans, a[i][j]);
                if (j > 0 && used[i][j - 1]) ans = min(ans, a[i][j]);
            }
        }

        cout << ans;

        for (pair<int, int> p : P[k]) {
            int i = p.first, j = p.second;
            if (a[i][j] == ans) {
                if (i == 0 && j == 0) used[i][j] = true;
                else {
                    if (i > 0 && used[i - 1][j]) used[i][j] = true;
                    if (j > 0 && used[i][j - 1]) used[i][j] = true;
                }
            }
        }
    }

    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int tests = 1; //cin >> tests;
    for (int i = 0; i < tests; ++i) {
        solve();
    }
}