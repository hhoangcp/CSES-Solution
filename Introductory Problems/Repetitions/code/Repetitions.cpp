
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n, res = 0;
char S[1000006];

int main() {
    scanf("%s", S+1); n = strlen(S+1);

    for(int i=1, len = 1; i<=n; ++i, ++len)
    if (i == n || S[i] != S[i+1]) {
        res = max(res, len);
        len = 0;
    }

    cout << res;
    return 0;
}
