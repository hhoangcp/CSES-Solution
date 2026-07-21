
#include <bits/stdc++.h>
#define pub push_back
#define pob pop_back
#define ll long long
#define ld long double
#define uint128 __uint128_t
#define int128 __int128
#define uint unsigned int
#define ull unsigned long long
#define ldouble double

using namespace std;

const ld EPS = 1e-9;
bool eq(ld a, ld b) { return fabs(a-b) <= fabs(a+b) * EPS; }
int sgn(ld a) { return (a > EPS) - (a < -EPS); }
struct P2 { ld x, y; P2(ld x = 0, ld y = 0) : x(x), y(y) {} }; 
struct Line { P2 A, B; Line() {}; Line(P2 A, P2 B) : A(A), B(B) {} };
bool operator < (P2 A, P2 B) { return A.x < B.x || (eq(A.x, B.x) && A.y < B.y); }
bool operator == (P2 A, P2 B) { return eq(A.x, B.x) && eq(A.y, B.y); }
P2 operator + (P2 A, P2 B) { return {A.x + B.x, A.y + B.y}; }
P2 operator - (P2 A, P2 B) { return {A.x - B.x, A.y - B.y}; }
ld cross(P2 A, P2 B) { return A.x * B.y - B.x * A.y; }
ld cross(P2 A, P2 B, P2 C) { return cross(B - A, C - A); }
ld dot(P2 A, P2 B) { return A.x * B.x + A.y * B.y; }
ld dot(P2 A, P2 B, P2 C) { return dot(B - A, C - A); }
ld abs2(P2 A) { return A.x * A.x + A.y * A.y; }
ld abs(P2 A) { return sqrtl(abs2(A)); }
ld dist(P2 A, P2 B) { return abs(B - A); }
P2 conj(P2 A) { return {A.x, -A.y}; }
P2 perp(P2 A) { return {-A.y, A.x}; }
P2 operator * (P2 A, ld B) { return {A.x * B, A.y * B}; } 
P2 operator / (P2 A, ld B) { return {A.x / B, A.y / B}; } 
P2 operator * (P2 A, P2 B) { return {A.x * B.x - A.y * B.y, A.x * B.y + B.x * A.y}; }
P2 operator / (P2 A, P2 B) { return A * conj(B) / abs2(B); }
P2 unit(P2 A) { return A / abs(A); }
int half(P2 A) { return A.y != 0 ? sgn(A.y) : -sgn(A.x); }
bool angleCmp(P2 a, P2 b) { int A = half(a), B = half(b); return A == B ? cross(a,b) > 0 : A < B; }
P2 reflect(P2 P, Line L) { P2 a = L.A, d = L.B-L.A; return a+conj((P-a)/d)*d; }
P2 foot(P2 P, Line L) { return (P+reflect(P,L))/2.0; }
bool onSeg(P2 P, Line L) { return sgn(cross(L.A,L.B,P)) == 0 && sgn(dot(P,L.A,L.B)) <= 0; }
vector<P2> lineIsect(Line A, Line B) {
    ld a0 = cross(A.A, A.B, B.A), a1 = cross(A.A, A.B, B.B); 
    if (a0 == a1) return a0 == 0 ? vector<P2>{B.A,B.B} : vector<P2>{};
    return {(B.B*a0-B.A*a1)/(a0-a1)};
}
ld lineDist(P2 P, Line L) { return abs(cross(P,L.A,L.B))/abs(L.A-L.B); }

pair<P2, ld> cenArea(vector<P2> P) {
    if (P.size() < 3) return {P2(), -1};
    P2 cen; ld area = 0; int sz = P.size();
    for(int i = 0; i < sz; ++i) {
        int j = (i + 1) % sz; ld a = cross(P[i], P[j]);
        cen = cen + a * (P[i] + P[j]), area += a;
    }
    return {cen / area / 3.0L, area / 2.0L};
}

int inPoly(P2 A, vector<P2> P) {
    int n = P.size(), ans = 0;
    for(int i = 0; i < n; ++i) {
        P2 x = P[i], y = P[(i+1)%n]; if (x.y > y.y) swap(x, y);
        if (onSeg(A, Line(x, y))) return 0;
        ans ^= (x.y <= A.y && A.y < y.y && cross(A,x,y) > 0);
    }
    return ans ? -1 : 1;
}

bool inPolyCW(P2 A, vector<P2> P) {
    if (cross(P.back(), A, P[0]) <= 0 || cross(P[0], A, P[1]) <= 0) return false;
    int n = P.size(), l = 1, r = n - 1;
    while (l + 1 < r) {
        int m = (l + r) >> 1;
        if (cross(P[0], P[m], A) <= 0) l = m; else r = m;
    }
    if (cross(P[l], P[l + 1], A) < 0) return true;
    return false;
}

vector<P2> convexHull2D(vector<P2> P) {
    sort(P.begin(), P.end());  
    vector<int> Top, Down; Top.pub(0); Down.pub(0); int n=P.size();
    for(int i = 1; i < n; ++i) {
        if (i == n - 1 || cross(P[0], P[i], P[n - 1]) < 0) {
            while (Top.size()>1 && cross(P[Top[Top.size()-2]],P[Top.back()],P[i]) >= 0) Top.pob();
            Top.pub(i);
        }
        if (i == n - 1 || cross(P[0], P[i], P[n - 1]) > 0) {
            while (Down.size()>1 && cross(P[Down[Down.size()-2]],P[Down.back()],P[i]) <= 0) Down.pob();
            Down.pub(i);
        }
    }
    vector<P2> ans;
    for(int i = 0; i < (int) Down.size(); ++i) ans.pub(P[Down[i]]);
    for(int i = Top.size() - 2; i > 0; --i) ans.pub(P[Top[i]]);
    return ans;
}

vector<P2> minkowski_sum(vector<P2> A, vector<P2> B) {
    if (A.size() > B.size()) swap(A, B);
    if (A.empty()) return {};
    if (A.size() == 1) {
        for(int i = 0; i < (int) B.size(); ++i) B[i] = B[i] + A[0];
        return B;
    }
    rotate(A.begin(), min_element(A.begin(), A.end()), A.end());
	rotate(B.begin(), min_element(B.begin(), B.end()), B.end());
    A.push_back(A[0]), A.push_back(A[1]);
    B.push_back(B[0]), B.push_back(B[1]);
    vector<P2> ans; int i = 0, j = 0;
    while (i < (int) A.size() - 2 || j < (int) B.size() - 2) {
        ans.push_back(A[i] + B[j]); 
        ld crs = cross(A[i+1]-A[i],B[j+1]-B[j]);
        i += (crs >= 0), j += (crs <= 0);
    }
    return ans;
}
ld diameter2(vector<P2> P) { // squared diameter
    vector<P2> A = convexHull2D(P), B = A;
    for(int i = 0; i < (int) B.size(); ++i) B[i] = B[i] * -1;
    vector<P2> C = minkowski_sum(A, B);
    ld ans = 0; for(P2 t: C) ans = max(ans, abs2(t));
    return ans;
}


#define cmp(i, j) sgn(cross(perp(A), P[i % n] - P[j % n]))
#define extr(i) cmp(i + 1, i) >= 0 && cmp(i, i - 1 + n) < 0
int extrVertex(vector<P2> P, P2 A) {
    int n = P.size(), l = 0, r = n;
    if (extr(0)) return 0;
    while (l + 1 < r) {
        int m = (l + r) >> 1;
        if (extr(m)) return m;
        int ls = cmp(l + 1, l), ms = cmp(m + 1, m);
        if (ls < ms || (ls == ms && ls == cmp(l, m))) r = m;
        else l = m;
    }
    return l;
}
vector<int> same(Line L, vector<P2> P, int a) {
    // points on same parallel as a
    int n = P.size(); P2 A = perp(L.A - L.B);
    if (cmp(a + n - 1, a) == 0) return {(a + n - 1) % n, a};
    if (cmp(a, a + 1) == 0) return {a, (a + 1) % n};
    return {a};
}
pair<int, vector<int>> lineHull(Line L, vector<P2> P) {
    #define cmpL(i) sgn(cross(L.A,L.B,P[i]))
    int n = P.size(); assert(n > 1);
    int endA = extrVertex(P, perp(L.A-L.B));
    if (cmpL(endA) >= 0) return {1, same(L,P,endA)};
    int endB = extrVertex(P, perp(L.B-L.A));
    if (cmpL(endB) <= 0) return {-1, same(L,P,endB)};
    array<int, 2> ans;
    for(int i = 0; i < 2; ++i) {
        int l = endA, r = endB; if (l > r) r += n;
        while (l < r) {
            int m = (l + r + 1) / 2;
            if (cmpL(m % n) == cmpL(endA)) l = m;
            else r = m - 1;
        }
        ans[i] = l % n, swap(endA, endB);
    }
    if (cmpL((ans[0]+1)%n)==0) ans[0]=(ans[0]+1)%n;
    return {0, {(ans[1] + 1) % n, ans[0]}};
}   

void solve() {
    int n, m; cin >> n >> m; 
    vector<P2> P(n);
    for(P2 &p: P) cin >> p.x >> p.y;
    while (m--) {
        ld x, y; cin >> x >> y;
        int ans = inPoly({x, y}, P);

        if (ans == 0) cout << "BOUNDARY\n";
        else if (ans == -1) cout << "INSIDE\n";
        else cout << "OUTSIDE\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int tests = 1; //cin >> tests;
    for(int test = 1; test <= tests; ++test) {
        solve();
    }

    return 0;
}