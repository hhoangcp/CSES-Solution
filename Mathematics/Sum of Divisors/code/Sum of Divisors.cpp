
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

const llong mod = 1e9+7;
const llong inv2 = 5e8+4;
llong n, sum = 0;

int main() {
    cin >> n;

    llong i;
    for(i = 1; i * i <= n; ++i) {
        llong num = (n / i) % mod;
        (sum += num * i) %= mod;
    }

    while (i <= n) {
        llong num = n / i;
        llong j = n / num;

        llong delta = (((j - i + 1) % mod) * ((i + j) % mod)) % mod * inv2 % mod;
        (sum += (num * delta) % mod) %= mod;

        i = j + 1;
    }

    cout << sum;

    return 0;
}
