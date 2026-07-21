 
#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <climits>
#define mp make_pair
#define X first
#define Y second
#define llong long long
 
using namespace std;
 
const int MAX_N = 200000;
typedef pair<int, int> Point;
Point Points[MAX_N+1], temp[MAX_N+1];
int n;
 
bool cmp_y(const Point &A, const Point &B) {
    return A.Y < B.Y;
}
 
llong Dist_sqr(const Point &A, const Point &B) {
    return (1LL * A.X - B.X) * (1LL * A.X - B.X) + (1LL * A.Y - B.Y) * (1LL * A.Y - B.Y);
}
 
llong Divide_and_Conquer(int Left, int Right) {
    if (Left >= Right) return LLONG_MAX;
    if (Right - Left == 1) {
        if (Points[Left].Y > Points[Right].Y) swap(Points[Left], Points[Right]);
        return Dist_sqr(Points[Left], Points[Right]);
    }
 
    int Mid = (Left + Right) / 2;
    int x_median = Points[Mid].X;
 
    llong dl = Divide_and_Conquer(Left, Mid);
    llong dr = Divide_and_Conquer(Mid + 1, Right);
    llong d = min(dl, dr);
 
    merge(Points + Left, Points + Mid + 1, Points + Mid + 1, Points + Right + 1, temp, cmp_y);
    copy(temp, temp + Right - Left + 1, Points + Left);
     
    for(int i = Left, cnt = 0; i <= Right; ++i)
    if ((1LL * Points[i].X - x_median) * (1LL * Points[i].X - x_median) < d) {
        for(int j = cnt - 1; j >= 0; --j) {
            if ((1LL * Points[i].Y - temp[j].Y) * (1LL * Points[i].Y - temp[j].Y) >= d) break;
 
            d = min(d, Dist_sqr(Points[i], temp[j]));
        }
 
        temp[cnt++] = Points[i];
    }
 
    return d;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
 
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int x, y; cin >> x >> y;
        Points[i] = mp(x, y);
    }
 
    sort(Points, Points + n);
 
    ///cout << fixed << setprecision(9) << sqrt(Divide_and_Conquer(0, n-1);
    cout << Divide_and_Conquer(0, n-1);
 
    return 0;
}