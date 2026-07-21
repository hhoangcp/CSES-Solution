
#include <cstdio>
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

struct Data {
    int a, b, p;

    bool operator < (const Data &other) const {
        return b < other.b;
    }
} P[200006];

llong dp[200006];
int n;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;
    for(int i=1; i<=n; ++i) cin >> P[i].a >> P[i].b >> P[i].p;

    sort(P+1, P+n+1);
    for(int i=1; i<=n; ++i) {
        int l = 1, r = i-1, p = 0;

        while (l <= r) {
            int mid = (l + r) >> 1;

            if (P[mid].b < P[i].a) {
                p = mid;
                l = mid + 1;
            } else r = mid - 1;
        }

        dp[i] = max(dp[i-1], dp[p] + P[i].p);
    }

    cout << dp[n];

    return 0;
}
