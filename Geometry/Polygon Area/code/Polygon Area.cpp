
#include <cstdio>
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

struct Point {
    llong x, y;
} P[100006];

int n;
llong area = 0;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;
    for(int i=1; i <= n; ++i) {
        cin >> P[i].x >> P[i].y;

        if (i > 1) area += (P[i].x - P[i-1].x) * (P[i].y + P[i-1].y);
        if (i == n) area += (P[1].x - P[n].x) * (P[1].y + P[n].y);
    }

    cout << abs(area);

    return 0;
}
