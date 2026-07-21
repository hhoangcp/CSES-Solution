
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#define llong long long

using namespace std;

struct Segment {
    int x, l, r, type;

    bool operator < (const Segment &other) const {
        return x < other.x || (x == other.x && type < other.type);
    }
} P[200006];

struct Data {
    int cnt;
    llong len;
} Seg[1600006];

int Y[200006], n, ny;
llong area = 0;

void compress() {
    set<int> S;
    for(int i=1; i<=n; ++i) S.insert(P[i].l), S.insert(P[i].r);
    vector<int> V(S.begin(), S.end()); ny = V.size();

    for(int i=1, j; i<=n; ++i) {
        j = lower_bound(V.begin(), V.end(), P[i].l) - V.begin(); Y[j] = P[i].l, P[i].l = j;
        j = lower_bound(V.begin(), V.end(), P[i].r) - V.begin(); Y[j] = P[i].r, P[i].r = j;
    }
}

void Update(int id, int l, int r, int u, int v, int type) {
    if (v < l || r < u) return;
    if (u <= l && r <= v) {
        Seg[id].cnt += type;

        if (type == 1) Seg[id].len = Y[r] - Y[l-1];
        else if (Seg[id].cnt == 0) Seg[id].len = Seg[id*2+1].len + Seg[id*2+2].len;

        return;
    }

    int mid = (l + r) >> 1;

    Update(id*2+1, l, mid, u, v, type);
    Update(id*2+2, mid+1, r, u, v, type);

    if (Seg[id].cnt == 0) Seg[id].len = Seg[id*2+1].len + Seg[id*2+2].len;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n; n <<= 1;

    for(int i = 1; i <= n; i += 2) {
        int x, y, u, v; cin >> x >> y >> u >> v;

        P[i] = {x, y, v, 1};
        P[i+1] = {u, y, v, -1};
    }

    sort(P+1, P+n+1);
    compress(); --ny;

    for(int i = 1; i <= n; ++i) {
        area += Seg[0].len * (1LL * P[i].x - P[i-1].x);
        Update(0, 1, ny, P[i].l+1, P[i].r, P[i].type);
    }

    cout << area;

    return 0;
}
