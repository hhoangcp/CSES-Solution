/// Convex Hull Trick

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <deque>
#define llong long long

using namespace std;

struct Line {
    int a;
    llong b;

    llong get_Y(int X) {
        return 1LL * a * X + b;
    }
};

deque <Line> DQ;
llong dp[200006];
int n, s[200006], C;

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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> C;
    Update({C, 0LL});

    for(int i = 1; i <= n; ++i) cin >> s[i];
    for(int i = 1; i <= n; ++i) {
        int f; cin >> f;
        dp[i] = Query(s[i]);
        Update({f, dp[i]});
    }

    cout << dp[n];

    return 0;
}
