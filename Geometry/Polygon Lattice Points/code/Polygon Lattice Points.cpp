/// Pick's Theorem

#include <cstdio>
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

struct Point {
    int x, y;
} P[100006];

int n;

llong GCD(llong X, llong Y) {
    if (X == 0 || Y == 0) return X + Y;
    return __gcd(X, Y);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;

    llong B = 0, S2 = 0;
    for(int i=1; i<=n; ++i) {
        cin >> P[i].x >> P[i].y;

        if (i > 1) {
            B += GCD(abs(1LL * P[i].x - P[i-1].x), abs(1LL * P[i].y - P[i-1].y));
            S2 += (1LL * P[i].x - P[i-1].x) * (1LL * P[i].y + P[i-1].y);
        }

        if (i == n) {
            B += GCD(abs(1LL * P[1].x - P[i].x), abs(1LL * P[1].y - P[i].y));
            S2 += (1LL * P[1].x - P[i].x) * (1LL * P[1].y + P[i].y);
        }
    }

    S2 = abs(S2);
    cout << (S2 + 2 - B) / 2 << ' ' << B;

    return 0;
}
