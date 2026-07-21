
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int dp[2006];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    dp[0] = dp[1] = dp[2] = 0;
    for(int i = 3; i < 2000; ++i) {
        set<int> S;

        for(int j = 1; 2 * j < i; ++j) S.insert(dp[j] ^ dp[i-j]);

        dp[i] = 0;
        while (S.count(dp[i])) ++dp[i];
    }

    int t; cin >> t;
    while (t--) {
        int x; cin >> x;

        if (x >= 2000 || dp[x] != 0) cout << "first\n";
        else cout << "second\n";
    }

    return 0;
}
