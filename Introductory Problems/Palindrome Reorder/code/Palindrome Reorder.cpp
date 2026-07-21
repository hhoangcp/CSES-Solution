
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n, num[26];
char S[1000006];

int main() {
    scanf("%s", S+1);  n = strlen(S+1);

    for(int i=1; i<=n; ++i) ++num[S[i]-'A'];

    int cnt = 0;
    for(int i=0; i<26; ++i) cnt += num[i] % 2;

    if ((n & 1) == 1 && cnt != 1) puts("NO SOLUTION");
    else if ((n & 1) == 0 && cnt != 0) puts("NO SOLUTION");
    else {
        int Left = 1, Right = n;

        for(int i=0; i<26; ++i)
        while (num[i] >= 2) {
            num[i] -= 2;
            S[Left++] = i + 'A';
            S[Right--] = i + 'A';
        }

        if (n & 1) {
            for(int i=0; i<26; ++i)
            if (num[i]) {
                S[(n + 1) / 2] = i + 'A';
                break;
            }
        }

        puts(S+1);
    }

    return 0;
}
