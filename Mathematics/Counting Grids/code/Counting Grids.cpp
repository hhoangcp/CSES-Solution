/// Burnside's lemma

#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

const llong mod = 1e9+7;
const llong phi = 1e9+6;

llong power(llong A, llong N) {
    llong res = 1;

    for(; N > 0; N >>= 1) {
        if (N & 1) res = res * A % mod;
        A = A * A % mod;
    }

    return res;
}

int n;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;

    llong res = power(2, 1LL * n * n);
    if (n & 1) {
        llong R13 = 1LL * ((n - 1) / 2) * ((n - 1) / 2 + 1) + 2;
        llong R2 = (1LL * ((2 * n - 2 - 4) / 4 + 1) * (2 * n + 2) / 2) + 1;
        res = (res + power(2, R13 % phi) + power(2, R2 % phi)) % mod;
    } else {
        llong R13 = 1LL * n * n / 4 + 1;
        llong R2 = 1LL * ((2 * n - 4) / 4 + 1) * (2 * n) / 2;
        res = (res + power(2, R13 % phi) + power(2, R2 % phi)) % mod;
    }

    (res *= power(4, phi - 1)) %= mod;
    cout << res;

    return 0;
}
