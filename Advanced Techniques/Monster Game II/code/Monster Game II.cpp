/// Li-Chao Tree

#include <cstdio>
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

const int MAX = 1e6;

struct Data {
    int a;
    llong b;

    llong get_y(int x) {
        return 1LL * a * x + b;
    }
} Seg[4000006];

void Update(int id, int l, int r, Data P) {
    int mid = (l + r) >> 1;

    bool Lef = P.get_y(l) < Seg[id].get_y(l);
    bool Mid = P.get_y(mid) < Seg[id].get_y(mid);

    if (Mid) swap(P, Seg[id]);

    if (l == r) return;
    else if (Lef != Mid) Update(id*2+1, l, mid, P);
    else Update(id*2+2, mid+1, r, P);
}

llong Query(int id, int l, int r, int p) {
    if (l > p || r < p) return 1e18;
    llong ans = Seg[id].get_y(p);
    if (l == r) return ans;

    int mid = (l + r) >> 1;
    ans = min(ans, Query(id*2+1, l, mid, p));
    ans = min(ans, Query(id*2+2, mid+1, r, p));

    return ans;
}

llong res = 0;
int s[200006], n, c;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> c;
    for(int i = 0; i <= 4*MAX; ++i) Seg[i] = {0, (llong) 1e18};

    Update(0, 1, MAX, {c, 0LL});

    for(int i = 1; i <= n; ++i) cin >> s[i];
    for(int i = 1; i <= n; ++i) {
        int f; cin >> f;

        res = Query(0, 1, MAX, s[i]);
        Update(0, 1, MAX, {f, res});
    }

    cout << res;

    return 0;
}
