
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

llong dp[1000006];
int n, num[1000006];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; ++i) {
        int a; cin >> a;
        ++num[a];
    }

    for(int i = 1000000; i >= 1; --i) {
        int N = 0;
        for(int j = i; j <= 1000000; j += i) N += num[j];

        dp[i] = 1LL * N * (1LL * N - 1) / 2LL;
        for(int j = 2*i; j <= 1000000; j += i) dp[i] -= dp[j];
    }

    cout << dp[1];

    return 0;
}
