/// Convex Hull Trick

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <deque>
#define llong long long

using namespace std;

struct Line {
    llong a, b;

    llong get_Y(int X) {
        return a * X + b;
    }
};

deque <Line> DQ;

bool CW(const Line &A, const Line &B, const Line &C) {
    return (1LL * B.a - A.a) * (C.b - A.b) - (B.b - A.b) * (1LL * C.a - A.a) < 0;
}

void Update(Line P) {
    while ((int) DQ.size() > 1 && !CW(DQ[DQ.size()-2], DQ.back(), P)) DQ.pop_back();
    DQ.push_back(P);
}

llong Query(int X) {
    while ((int) DQ.size() > 1 && DQ[0].get_Y(X) >= DQ[1].get_Y(X)) DQ.pop_front();
    return DQ[0].get_Y(X);
}

llong dp[3006][3006], prefix[3006];
int k, n;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> k;
    for(int i = 1; i <= n; ++i) {
        int a; cin >> a;
        prefix[i] = prefix[i-1] + a;
        dp[i][1] = prefix[i] * prefix[i];
    }

    for(int i = 2; i <= k; ++i) {
        DQ.clear();

        Update({-2LL * prefix[i-1], dp[i-1][i-1] + prefix[i-1] * prefix[i-1]});
        for(int j = i; j <= n; ++j) {
            dp[j][i] = Query(prefix[j]) + prefix[j] * prefix[j];
            Update({-2LL * prefix[j], dp[j][i-1] + prefix[j] * prefix[j]});
        }
    }

    cout << dp[n][k];

    return 0;
}
