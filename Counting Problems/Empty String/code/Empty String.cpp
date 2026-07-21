
#include <iostream>
#include <algorithm>
#include <cstring>
#define llong long long

using namespace std;

const llong mod = 1e9+7;
llong dp[506][506], C[256][256];
int n;
char S[506];

int main() {
    scanf("%s", S+1); n = strlen(S+1);

    for(int i = 2; i <= n+1; ++i) dp[i][i-1] = 1LL;

    C[0][0] = 1;
    for(int i = 1; i <= n / 2; ++i) {
        C[i][0] = 1;
        for(int j = 1; j <= i; ++j) C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
    }

    for(int i = n-1; i >= 1; --i)
    for(int j = i+1; j <= n; j += 2) {
        dp[i][j] = 0;

        for(int k = i+1; k <= j; k += 2)
        if (S[i] == S[k]) {
            llong delta = dp[i+1][k-1] * dp[k+1][j] % mod;
            (delta *= C[(j-i+1)/2][(k-i+1)/2]) %= mod;
            (dp[i][j] += delta) %= mod;
        }
    }

    cout << dp[1][n];

    return 0;
}
