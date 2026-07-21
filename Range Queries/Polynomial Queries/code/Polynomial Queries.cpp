#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

struct Data {
    llong Lazy_1, Lazy_2;
    llong sum;
} SNode[800006];

int n, q;

llong cal(int x) {
    return 1LL * x * (x+1) / 2;
}

void down(int id, int l, int mid, int r) {
    SNode[id*2].Lazy_1 += SNode[id].Lazy_1;
    SNode[id*2].Lazy_2 += SNode[id].Lazy_2;
    SNode[id*2].sum += SNode[id].Lazy_1 * (mid - l + 1) + SNode[id].Lazy_2 * (cal(mid) - cal(l-1));
    ///
    SNode[id*2+1].Lazy_1 += SNode[id].Lazy_1;
    SNode[id*2+1].Lazy_2 += SNode[id].Lazy_2;
    SNode[id*2+1].sum += SNode[id].Lazy_1 * (r - mid) + SNode[id].Lazy_2 * (cal(r) - cal(mid));
    ///
    SNode[id].Lazy_1 = SNode[id].Lazy_2 = 0;
}

void update(int id, int l, int r, int u, int v, llong val) {
    if (l > v || r < u) return;
    if (u <= l && r <= v) {
        SNode[id].Lazy_1 -= val * (u-1);
        SNode[id].Lazy_2 += val;
        SNode[id].sum -= val * (u-1) * (r-l+1);
        SNode[id].sum += val * (cal(r) - cal(l-1));
        return;
    }
    ///
    int mid = (l + r) >> 1;
    down(id, l, mid, r);
    ///
    update(id*2, l, mid, u, v, val);
    update(id*2+1, mid+1, r, u, v, val);
    ///
    SNode[id].sum = SNode[id*2].sum + SNode[id*2+1].sum;
}

llong query(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return 0LL;
    if (u <= l && r <= v) return SNode[id].sum;
    ///
    int mid = (l + r) >> 1;
    down(id, l, mid, r);
    ///
    return query(id*2, l, mid, u, v) + query(id*2+1, mid+1, r, u, v);
}

int main() {
    ///freopen("inp.txt", "r", stdin);
    ///freopen("out.txt", "w", stdout);
    ///
    scanf("%d%d", &n, &q);
    for(int i=1; i<=n; ++i) {
        int a; scanf("%d", &a);
        update(1, 1, n, i, i, a);
    }
    ///
    for(int i=1; i<=q; ++i) {
        int type, u, v; scanf("%d%d%d", &type, &u, &v);
        if (type == 1) update(1, 1, n, u, v, 1LL);
        else cout << query(1, 1, n, u, v) << "\n";
    }
    return 0;
}
