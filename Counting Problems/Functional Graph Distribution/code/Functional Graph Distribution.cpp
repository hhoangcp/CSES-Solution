
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

const llong mod = 1e9+7;
llong C[5006][5006], cycle[5006][5006], power[5006];
int n;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;

    power[0] = 1;
    for(int i = 1; i <= n; ++i) power[i] = power[i-1] * n % mod;

    C[0][0] = 1;
    for(int i = 1; i <= n; ++i) {
        C[i][0] = 1;
        for(int j = 1; j <= i; ++j) C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
    }

    cycle[1][1] = 1;
    for(int i = 2; i <= n; ++i)
    for(int j = 1; j <= n; ++j)
        cycle[i][j] = ((1LL * i - 1) * cycle[i-1][j] + cycle[i-1][j-1]) % mod;

    for(int k = 1; k <= n; ++k) {
        llong ans = 0;

        for(int i = 1; i <= n; ++i) {
            llong delta = C[n-1][i-1] * power[n - i] % mod;
            (ans += delta * cycle[i][k]) %= mod;
        }

        cout << ans << '\n';
    }

    return 0;
}
