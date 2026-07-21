/// Burnside's lemma

#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

int n, k;

int GCD(int A, int B) {
    if (A == 0) return B;
    if (B == 0) return A;
    return __gcd(A, B);
}

const llong mod = 1e9+7;

llong power(llong A, llong N) {
    llong res = 1;

    for(; N > 0; N >>= 1) {
        if (N & 1) res = res * A % mod;
        A = A * A % mod;
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> k;

    llong res = 0;
    for(int i = 0; i < n; ++i) (res += power(k, GCD(n, i))) %= mod;
    (res *= power(n, mod - 2)) %= mod;

    cout << res;

    return 0;
}
