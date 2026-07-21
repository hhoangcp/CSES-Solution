
#pragma GCC target("popcnt")
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

llong a[3006][50];
int n;
char S[3006];

int main() {
    scanf("%d", &n); int block = (n + 63) >> 6;
    for(int i = 1; i <= n; ++i) {
        scanf("%s", S);

        for(int j = 0; j < n; ++j)
        if (S[j] == '1') a[i][j >> 6] |= (1LL << (j % 64));
    }

    llong res = 0;
    for(int i = 1; i < n; ++i)
    for(int j = i+1; j <= n; ++j) {
        int cnt = 0;

        for(int k = 0; k < block; ++k)
            cnt += __builtin_popcountll(a[i][k] & a[j][k]);

        res += cnt * (cnt - 1) / 2;
    }

    cout << res;

    return 0;
}
