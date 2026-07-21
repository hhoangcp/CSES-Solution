
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

stack<int> ans;
int n, Z[1000006], PF[1000006];
char S[1000006];

void Prefix_Function() {
    PF[1] = 0;
    for(int i = 2; i <= n; ++i) {
        int j = PF[i-1];

        while (j > 0 && S[i] != S[j+1]) j = PF[j];
        if (S[i] == S[j+1]) ++j;

        PF[i] = j;
    }
}

int main() {
    scanf("%s", S+1); n = strlen(S+1);

    int L = 0, R = 0;
    for(int i = 2; i <= n; ++i) {
        if (R >= i) Z[i] = min(Z[i-L+1], R-i+1);

        while (i + Z[i] <= n && S[i + Z[i]] == S[Z[i]+1]) ++Z[i];
        if (i + Z[i] - 1 > R) {
            L = i;
            R = i + Z[i] - 1;
        }
    }

    Prefix_Function();
    for(int i = 1; i <= n; ++i) cout << Z[i] << ' ';
    cout << '\n';
    for(int i = 1; i <= n; ++i) cout << PF[i] << ' ';

    return 0;
}
