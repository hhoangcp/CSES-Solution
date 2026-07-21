
#include <iostream>
#include <algorithm>
#define ldouble long double

using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

ldouble dp[106][10][10], ans[10][10];
int k;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> k;

    for(int i = 1; i <= 8; ++i)
    for(int j = 1; j <= 8; ++j) ans[i][j] = 1;

    for(int i = 1; i <= 8; ++i)
    for(int j = 1; j <= 8; ++j) {
        for(int t = 0; t <= k; ++t)
        for(int x = 1; x <= 8; ++x)
        for(int y = 1; y <= 8; ++y) dp[t][x][y] = 0;

        dp[0][i][j] = 1;

        for(int t = 1; t <= k; ++t)
        for(int x = 1; x <= 8; ++x)
        for(int y = 1; y <= 8; ++y) {
            int cur = 0;

            for(int s = 0; s < 4; ++s) {
                int u = x + dx[s], v = y + dy[s];
                if (1 <= u && u <= 8 && 1 <= v && v <= 8) ++cur;
            }

            for(int s = 0; s < 4; ++s) {
                int u = x + dx[s], v = y + dy[s];
                if (1 <= u && u <= 8 && 1 <= v && v <= 8)
                    dp[t][u][v] += dp[t-1][x][y] / cur;
            }
        }

        for(int x = 1; x <= 8; ++x)
        for(int y = 1; y <= 8; ++y)
            ans[x][y] *= (1.0L - dp[k][x][y]);
    }

    ldouble sum = 0;
    for(int x = 1; x <= 8; ++x)
    for(int y = 1; y <= 8; ++y) sum += ans[x][y];

    (cout << fixed).precision(6);
    cout << sum;

    return 0;
}
