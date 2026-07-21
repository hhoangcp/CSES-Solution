
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n, M[2000006];
char S[2000006];

int main() {
    scanf("%s", S+1); n = strlen(S+1);
    for(int i = 2*n; i >= 2; i -= 2) S[i] = S[i>>1];

    n = n*2+1;
    for(int i=1; i<=n; i += 2) S[i] = '#';

    int L = 0, R = 0, res = 0, center_res;
    for(int i = 1; i <= n; ++i) {
        if (R >= i) M[i] = min(R - i, M[2*L-i]);
        while (i+M[i]+1 <= n && i-M[i]-1>0 && S[i+M[i]+1] == S[i-M[i]-1]) ++M[i];

        if (res < M[i]) {
            res = M[i];
            center_res = i;
        }

        if (i + M[i] > R) {
            L = i;
            R = i + M[i];
        }
    }

    for(int i = center_res - res + 1; i <= center_res + res - 1; ++i)
    if (!(i & 1)) putchar(S[i]);

    return 0;
}
