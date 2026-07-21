
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int mod = 1e9+7;
const int inv_2 = 5e8+4;
int dp[125256], n;

int main() {
    cin >> n;
    int sum = n * (n+1) / 2;

    if (sum & 1) {
        cout << 0;
        return 0;
    }

    dp[0] = 1;
    for(int i=1; i<=n; ++i)
    for(int j=sum/2; j>=i; --j) dp[j] = (dp[j] + dp[j-i]) % mod;

    cout << (1LL * dp[sum / 2] * inv_2) % mod;

    return 0;
}
