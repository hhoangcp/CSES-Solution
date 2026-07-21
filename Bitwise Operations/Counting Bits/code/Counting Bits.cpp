
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

int Left_Most_Bit(llong x) {
    int m = 0;

    while (x > 1) {
        x >>= 1;
        ++m;
    }

    return m;
}

int Next_Left_Most_Bit(llong x, int p) {
    llong tmp = (1LL << p);
    while (x < tmp) {
        tmp >>= 1;
        --p;
    }

    return p;
}

llong Count_Set_Bits(llong x, int p);

llong Count_Set_Bits(llong x) {
    int p = Left_Most_Bit(x);
    return Count_Set_Bits(x, p);
}

llong Count_Set_Bits(llong x, int p) {
    if (x <= 0) return 0LL;

    p = Next_Left_Most_Bit(x, p);
    if (x == (1LL << (p + 1)) - 1) return (1LL * p + 1) * (1LL << p);

    x -= (1LL << p);
    return x + 1 + Count_Set_Bits(x) + 1LL * p * (1LL << (p - 1));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    llong n; cin >> n;
    cout << Count_Set_Bits(n);

    return 0;
}
