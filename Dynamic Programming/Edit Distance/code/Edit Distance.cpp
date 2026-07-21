
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, dp[2][5006];
char S[5006], T[5006];

int main() {
    scanf("%s%s", S+1, T+1);
    n = strlen(S+1), m = strlen(T+1);

    for(int i=1; i<=m; ++i) dp[1][i] = i;
    for(int i=1; i<=n; ++i) {
        for(int j=0; j<=m; ++j) dp[0][j] = dp[1][j], dp[1][j] = 0;
        dp[1][0] = i;

        for(int j=1; j<=m; ++j) {
            dp[1][j] = min(min(dp[0][j-1] + 1, dp[0][j] + 1), dp[1][j-1] + 1);
            if (S[i] == T[j]) dp[1][j] = min(dp[1][j], dp[0][j-1]);
        }
    }

    cout << dp[1][m];

    return 0;
}
