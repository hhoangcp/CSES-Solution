
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int mod = 1e9+7;
int dp[500006], pre[26];
char S[500006];

int main() {
    scanf("%s", S+1); int n = strlen(S+1);

    fill(pre, pre+26, -1);

    dp[0] = 1;
    for(int i = 1; i <= n; ++i) {
        int c = S[i] - 'a';
        dp[i] = dp[i-1] * 2 % mod;

        if (pre[c] >= 0) ((dp[i] -= dp[pre[c]]) += mod) %= mod;
        pre[c] = i - 1;
    }

    cout << (dp[n] + mod - 1) % mod;

    return 0;
}
