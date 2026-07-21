
#include <iostream>
#include <algorithm>
#include <cstring>
#define llong long long

using namespace std;

const llong mod = 1e9+7;
llong fact[1000006];
llong inv[1000006], inv_f[1000006];
int n, num[26];
char S[1000006];

int main() {
    scanf("%s", S+1); n = strlen(S+1);
    for(int i = 1; i <= n; ++i) ++num[S[i] - 'a'];

    fact[0] = fact[1] = inv[0] = inv[1] = inv_f[0] = inv_f[1] = 1;
    for(int i = 2; i <= n; ++i) {
        fact[i] = fact[i-1] * i % mod;
        inv[i] = mod - ((mod / i) * inv[mod % i] % mod);
        inv_f[i] = inv_f[i-1] * inv[i] % mod;
    }

    llong ans = fact[n];
    for(int i = 0; i < 26; ++i) (ans *= inv_f[num[i]]) %= mod;

    cout << ans;

    return 0;
}
