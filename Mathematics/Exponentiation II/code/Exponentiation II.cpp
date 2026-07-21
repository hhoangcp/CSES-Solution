#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

const llong mod = 1e9+7;

llong Power(llong A, llong N, llong M) {
    if (N == 0) return 1LL % M;

    llong tmp = Power(A, N >> 1, M);
    tmp = tmp * tmp % M;

    if (N & 1) tmp = tmp * A % M;
    return tmp;
}

int n;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;
    while (n--) {
        llong a, b, c; cin >> a >> b >> c;

        if (a == 0) {
            cout << (b == 0 && c > 0 ? 1 : 0) << '\n';
        } else {
            llong e = Power(b, c, mod - 1);
            if (e == 0) e = mod - 1;
            cout << Power(a, e, mod) << '\n';
        }
    }

    return 0;
}
