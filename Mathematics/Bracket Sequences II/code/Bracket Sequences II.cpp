/// https://codeforces.cc/blog/entry/87585

#include <iostream>
#include <algorithm>
#include <cstring>
#define llong long long

using namespace std;

const llong mod = 1e9+7;
llong inv[1000006], C[1000006];
int n, k = 0;
char S[1000006];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    scanf("%d%s", &n, S+1); int len = strlen(S+1);
    if (n & 1) {
        cout << 0;
        return 0;
    }

    n -= len;
    for(int i = 1; i <= len; ++i) {
        if (S[i] == '(') ++k; else --k;
        if (k < 0) {
            cout << 0;
            return 0;
        }
    }

    n += k; n >>= 1; n -= k;

    inv[0] = inv[1] = 1;
    for(int i = 2; i <= n + k + 1; ++i) inv[i] = mod - ((mod / i) * inv[mod % i] % mod);

    C[0] = 1;
    for(int i = 1; i <= n; ++i) {
        llong delta = (2LL * i + k - 1) * (2LL * i + k) % mod;
        (delta *= (inv[i] * inv[i+k+1]) % mod) %= mod;

        C[i] = C[i-1] * delta % mod;
    }

    cout << C[n];

    return 0;
}
