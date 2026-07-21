
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

const llong mod = 1e9+7;
llong fact[20000006], inv[2000006];
int n, k;

llong power(llong A, llong B) {
    llong ans = 1LL;

    for(; B > 0; B >>= 1) {
        if (B & 1) (ans *= A) %= mod;
        (A *= A) %= mod;
    }

    return ans;
}

llong C(int N, int R) {
    return fact[N] * (inv[R] * inv[N-R] % mod) % mod;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> k;

    inv[0] = inv[1] = fact[0] = fact[1] = 1;
    for(int i = 2; i <= n; ++i) {
        fact[i] = fact[i-1] * i % mod;
        inv[i] = mod - ((mod / i) * inv[mod % i] % mod);
    }

    for(int i = 1; i <= n; ++i) (inv[i] *= inv[i-1]) %= mod;

    llong ans = 0;
    for(int i = k, t = 1; i >= 1; t *= -1, --i) {
        llong delta = power(i, n) * C(k, i);

        ans = (ans + delta * t + mod) % mod;
    }

    cout << ans;

    return 0;
}
