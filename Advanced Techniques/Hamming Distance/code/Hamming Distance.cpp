
#pragma GCC target("popcnt")
#include <iostream>
#include <algorithm>

using namespace std;

int n, k, a[20006];
char S[36];

int main() {
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; ++i) {
        scanf("%s", S);

        for(int j = 0; j < k; ++j)
        if (S[j] == '1') a[i] |= (1 << j);
    }

    int ans = 32;
    for(int i = 1; i <= n; ++i)
    for(int j = i + 1; j <= n; ++j)
        ans = min(ans, (int) __builtin_popcount(a[i] ^ a[j]));

    cout << ans;

    return 0;
}
