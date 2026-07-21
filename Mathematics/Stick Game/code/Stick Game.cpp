
#include <iostream>
#include <algorithm>

using namespace std;

bool dp[1000006];
int n, k, p[106];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> k;
    for(int i = 1; i <= k; ++i) cin >> p[i];

    dp[0] = false;
    for(int i = 1; i <= n; ++i) {
        dp[i] = false;

        for(int j = 1; j <= k; ++j)
        if (i >= p[j]) dp[i] |= !dp[i-p[j]];

        if (!dp[i]) cout << 'L'; else cout << 'W';
    }

    return 0;
}
