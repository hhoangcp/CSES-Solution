
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

const llong mod = 1e9+7;
llong fact[1000006];
llong inv[1000006], inv_f[1000006];
int n;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    fact[0] = fact[1] = inv[0] = inv[1] = inv_f[0] = inv_f[1] = 1;
    for(int i = 2; i <= 1000000; ++i) {
        fact[i] = fact[i-1] * i % mod;
        inv[i] = mod - ((mod / i) * inv[mod % i] % mod);
        inv_f[i] = inv_f[i-1] * inv[i] % mod;
    }

    cin >> n;
    while (n--) {
        int a, b; cin >> a >> b;
        cout << fact[a] * (inv_f[b] * inv_f[a - b] % mod) % mod << '\n';
    }

    return 0;
}
