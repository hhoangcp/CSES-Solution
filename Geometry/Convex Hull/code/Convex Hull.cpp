
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#define llong long long

using namespace std;

struct Point {
    int x, y;

    bool operator < (const Point &other) const {
        return y < other.y || (y == other.y && x < other.x);
    }
} P[200006];

vector<Point> Hull;
int n, ntop = 0, ndown = 0;

bool CW(const Point &A, const Point &B, const Point &C) {
    return (1LL * B.x - A.x) * (1LL * C.y - A.y) - (1LL * B.y - A.y) * (1LL * C.x - A.x) < 0;
}

bool CCW(const Point &A, const Point &B, const Point &C) {
    return (1LL * B.x - A.x) * (1LL * C.y - A.y) - (1LL * B.y - A.y) * (1LL * C.x - A.x) > 0;
}

void Convex_hull() {
    sort(P+1, P+n+1);

    for(int p = 0, sz = 0; p < 2; ++p) {
        for(int i=1; i<=n; ++i) {
            while ((int) Hull.size() - sz >= 2) {
                if (!CW(Hull[Hull.size() - 2], Hull.back(), P[i])) break;
                Hull.pop_back();
            }

            Hull.push_back(P[i]);
        }

        Hull.pop_back();
        sz = Hull.size();
        reverse(P+1, P+n+1);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;
    for(int i=1; i<=n; ++i) cin >> P[i].x >> P[i].y;

    Convex_hull();

    cout << Hull.size() << '\n';
    for(Point p: Hull) cout << p.x << ' ' << p.y << '\n';

    return 0;
}
