
#include <cstdio>
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

const int mod = 1e9+7;
llong dp[1000006][2];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    dp[1][0] = dp[1][1] = 1;
    for(int i=2; i<=1000000; ++i) {
        dp[i][0] = (dp[i-1][0] * 4 + dp[i-1][1]) % mod;
        dp[i][1] = (dp[i-1][0] + dp[i-1][1] * 2) % mod;
    }

    int t; cin >> t;
    while(t--) {
        int a; cin >> a;
        cout << (dp[a][0] + dp[a][1]) % mod << '\n';
    }

    return 0;
}
