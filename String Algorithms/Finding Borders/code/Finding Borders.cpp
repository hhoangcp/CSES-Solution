
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

stack<int> ans;
int n, Z[1000006];
char S[1000006];

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

        if (i + Z[i] - 1 == n) ans.push(Z[i]);
    }

    while (!ans.empty()) {
        cout << ans.top() << ' ';
        ans.pop();
    }

    return 0;
}
