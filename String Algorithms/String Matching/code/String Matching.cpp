
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, len, Z[2000006];
char S[1000006], T[2000006];

int main() {
    scanf("%s", S+1); n = strlen(S+1);
    scanf("%s", T+1); m = strlen(T+1);

    int len = m+1; T[len] = ' ';
    for(int i = 1; i <= n; ++i) T[++len] = S[i];

    int L = 0, R = 0;
    for(int i = 2; i <= len; ++i) {
        if (R >= i) Z[i] = min(Z[i-L+1], R-i+1);

        while (i + Z[i] <= len && T[i + Z[i]] == T[Z[i]+1]) ++Z[i];
        if (i + Z[i] - 1 > R) {
            L = i;
            R = i + Z[i] - 1;
        }
    }

    int ans = 0;
    for(int i = m+1; i <= len; ++i)
    if (Z[i] == m) ++ans;

    cout << ans;

    return 0;
}
