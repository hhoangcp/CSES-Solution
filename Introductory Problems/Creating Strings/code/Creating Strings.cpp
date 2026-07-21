
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

char S[10], T[40321][10];
int n, res = 0;

int main() {
    scanf("%s", S+1); n = strlen(S+1);

    sort(S+1, S+n+1);
    strcpy(T[++res]+1, S+1);
    while(next_permutation(S+1, S+n+1)) strcpy(T[++res]+1, S+1);

    cout << res << "\n";
    for(int i=1; i<=res; ++i) puts(T[i] + 1);

    return 0;
}
