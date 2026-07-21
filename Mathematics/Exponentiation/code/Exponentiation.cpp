
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

const llong mod = 1e9+7;

llong Power(int A, int N) {
    if (N == 0) return 1LL;

    llong tmp = Power(A, N >> 1);
    tmp = tmp * tmp % mod;

    if (N & 1) tmp = tmp * A % mod;
    return tmp;
}

int n;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;
    while (n--) {
        int a, n; cin >> a >> n;
        cout << Power(a, n) << '\n';
    }

    return 0;
}
