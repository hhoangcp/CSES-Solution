#include <algorithm>
#include <iostream>
#include <cassert>
#include <vector>
#define ll long long
#define ull unsigned long long

using namespace std;

int trace[1006][1006];
int a[1006], b[1006], dp[1006][1006];

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i) cin >> b[i];

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                trace[i][j] = 1;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                dp[i][j] = dp[i - 1][j];
                trace[i][j] = 2;
            } else {
                dp[i][j] = dp[i][j - 1];
                trace[i][j] = 3;
            }

    cout << dp[n][m] << '\n';
    vector<int> ans;
    int x = n, y = m;
    while (x > 0 && y > 0) {
        if (trace[x][y] == 1) {
            ans.push_back(a[x]);
            --x, --y;
        } else if (trace[x][y] == 2) --x;
        else --y;
    }

    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i) cout << ans[i] << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int tests = 1; //cin >> tests;
    for (int i = 0; i < tests; ++i) {
        solve();
    }
}