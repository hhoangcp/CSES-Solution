
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

const llong mod = 1e9+7;
const llong phi = 1e9+6;
int n, X[100006], K[100006];
llong Pre[100006], Suf[100006];

llong Power(llong A, llong N) {
    if (N == 0) return 1LL;

    llong tmp = Power(A, N >> 1);
    tmp = tmp * tmp % mod;

    if (N & 1) tmp = tmp * A % mod;
    return tmp;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;
    llong P = 1, sum = 1, N = 1;
    Pre[0] = Suf[n+1] = 1;

    for(int i = 1; i <= n; ++i) {
        cin >> X[i] >> K[i];
        (P *= (K[i] + 1)) %= mod;

        (sum *= ((Power(X[i], K[i] + 1) - 1 + mod) % mod * Power(X[i] - 1, mod - 2)) % mod) %= mod;
        (N *= Power(X[i], K[i])) %= mod;

        Pre[i] = Pre[i - 1] * (K[i] + 1) % phi;
    }

    llong mul = 1;
    for(int i = n; i >= 1; --i) {
        Suf[i] = Suf[i + 1] * (K[i] + 1) % phi;

        llong Pow = Pre[i-1] * Suf[i + 1] % phi;
        (mul *= Power(X[i], (1LL * K[i] * (K[i] + 1) / 2) % phi * Pow % phi)) %= mod;
    }

    cout << P << ' ' << sum << ' ' << mul;

    return 0;
}
