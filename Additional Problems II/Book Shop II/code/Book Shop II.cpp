
#include <iostream>
#include <algorithm>
#include <deque>
#define llong long long

using namespace std;

deque<int> DQ;
llong dp[106][100006];
int x[106], y[106], z[106], n, m;

void push(int i, int j) {
    while (!DQ.empty() && dp[i-1][DQ.back()] + (j - DQ.back()) / x[i] * y[i] <= dp[i-1][j]) DQ.pop_back();
    DQ.push_back(j);
}

void pop(int i) {
    while (!DQ.empty() && DQ.front() < i) DQ.pop_front();
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> x[i];
    for(int i = 1; i <= n; ++i) cin >> y[i];
    for(int i = 1; i <= n; ++i) cin >> z[i];

    for(int i=0; i * x[1] <= m && i <= z[1]; ++i) dp[1][i*x[1]] = i * y[1];

    for(int i=2; i<=n; ++i) {
        if (x[i] == 0) {
            for(int j=0; j<=m; ++j) dp[i][j] = dp[i-1][j] + y[i] * z[i];
            continue;
        }

        for(int j = 0; j < x[i]; ++j) {
            for(int k = j; k <= m; k += x[i]) {
                pop(k - z[i]*x[i]);
                push(i, k);

                int top_front = DQ.front();
                dp[i][k] = dp[i-1][top_front] + (k - top_front) / x[i] * y[i];
            }

            DQ.clear();
        }
    }

    llong res = 0;
    for(int i=1; i<=n; ++i)
    for(int j=0; j<=m; ++j) res = max(res, dp[i][j]);

    cout << res << "\n";

    return 0;
}
