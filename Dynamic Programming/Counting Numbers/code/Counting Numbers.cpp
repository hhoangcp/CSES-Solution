
#include <cstdio>
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

llong dp[26][16][2];
char C[26];
bool visited[26][16];

llong DP(int cur, int e, int Equal) {
    if (cur == 0) return 1LL;
    if (Equal == 0 && visited[cur][e]) return dp[cur][e][0];

    llong &tmp = dp[cur][e][Equal]; tmp = 0;
    if (Equal == 0) {
        visited[cur][e] = true;

        for(int i=0; i<=9; ++i)
        if (i != e) tmp = (tmp + DP(cur-1, i, 0));
    } else {
        for(int i=0; i<=C[cur]-'0'; ++i)
        if (i != e) tmp = (tmp + DP(cur-1, i, (int) (i == C[cur]-'0')));
    }

    return tmp;
}

llong Cal(llong X) {
    if (X < 10) return X;

    int n = 0;
    while (X > 0) {
        C[++n] = char(X % 10 + '0');
        X /= 10;
    }

    llong res = 0;
    for(int i=1; i<n; ++i)
    for(int j=1; j<=9; ++j) res += DP(i-1, j, 0);

    for(int i=1; i<=C[n] - '0'; ++i) res += DP(n-1, i, (int) (i == C[n] - '0'));
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    llong a, b; cin >> a >> b;
    cout << Cal(b) - Cal(a-1);

    return 0;
}
