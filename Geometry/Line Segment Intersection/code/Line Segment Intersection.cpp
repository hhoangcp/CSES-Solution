
#include <cstdio>
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

struct Point {
    llong x, y;
} P[5];

llong get_area(const Point &A, const Point &B, const Point &C) {
    return (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
}

bool On_Segment(const Point &cur, const Point &A, const Point &B) {
    if (get_area(A, cur, B) != 0) return false;
    return min(A.x, B.x) <= cur.x && cur.x <= max(A.x, B.x) && min(A.y, B.y) <= cur.y && cur.y <= max(A.y, B.y);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        for(int i=1; i<=4; ++i) cin >> P[i].x >> P[i].y;

        llong area_3 = get_area(P[1], P[3], P[2]);
        llong area_4 = get_area(P[1], P[4], P[2]);
        llong area_1 = get_area(P[3], P[1], P[4]);
        llong area_2 = get_area(P[3], P[2], P[4]);

        if (((area_1 >= 0 && area_2 < 0) || (area_1 < 0 && area_2 >= 0)
            || (area_1 > 0 && area_2 <= 0) || (area_1 <= 0 && area_2 > 0))
            && ((area_3 >= 0 && area_4 < 0) || (area_3 < 0 && area_4 >= 0)
            || (area_3 > 0 && area_4 <= 0) || (area_3 <= 0 && area_4 > 0))) {
            puts("YES");
            continue;
        }

        if (On_Segment(P[1], P[3], P[4]) || On_Segment(P[2], P[3], P[4])
            || On_Segment(P[3], P[1], P[2]) || On_Segment(P[4], P[1], P[2])) {
            puts("YES");
            continue;
        }

        puts("NO");
    }

    return 0;
}
