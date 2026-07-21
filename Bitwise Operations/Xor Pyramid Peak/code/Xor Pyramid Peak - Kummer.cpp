
#include <iostream>
#include <algorithm>

using namespace std;

int n, power[200006], bit[200006];

int Mod(int c, int n) {
    if (bit[n] - bit[c] - bit[n-c] > 0) return 0;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n; --n;

    for(int h = 1; h <= n; h <<= 1) power[h] = power[h >> 1] + 1;
    for(int i = 1; i <= n; ++i) bit[i] = bit[i - 1] + power[(i & (-i))];

    int Xor = 0;
    for(int i = 0; i <= n; ++i) {
        int a; cin >> a;
        Xor ^= a * Mod(i, n);
    }

    cout << Xor;

    return 0;
}
