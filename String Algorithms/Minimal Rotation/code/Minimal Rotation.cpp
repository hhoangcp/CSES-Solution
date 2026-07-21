
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int n, ans;
char S[2000006];

int main() {
    scanf("%s", S+1); n = strlen(S+1);
    for(int i = n+1; i<=2*n; ++i) S[i] = S[i-n];
    n *= 2;

    for(int i = 1; i * 2 <= n;) {
        ans = i;

        int j = i + 1, k = i;
        while (j <= n && S[k] <= S[j]) {
            if (S[k] < S[j]) k = i; else ++k;
            ++j;
        }

        while (i <= k) i += j - k;
    }

    for(int i = ans; i <= ans + n / 2 - 1; ++i) putchar(S[i]);

    return 0;
}
