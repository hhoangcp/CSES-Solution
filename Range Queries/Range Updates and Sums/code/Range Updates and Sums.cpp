#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

struct Data {
    bool Set_All;
    llong sum;
    llong increase;
    llong Set;
} SNode[800006];

int n, q;

void down(int id, int l, int mid, int r) {
    if (SNode[id].Set_All) {
        SNode[id*2] = SNode[id*2+1] = SNode[id];
        SNode[id*2].sum = (SNode[id].Set + SNode[id].increase) * (mid - l + 1);
        SNode[id*2+1].sum = (SNode[id].Set + SNode[id].increase) * (r - mid);
    } else {
        SNode[id*2].increase += SNode[id].increase;
        SNode[id*2+1].increase += SNode[id].increase;
        SNode[id*2].sum += SNode[id].increase * (mid - l + 1);
        SNode[id*2+1].sum += SNode[id].increase * (r - mid);
    }
    ///
    SNode[id].increase = SNode[id].Set = 0;
    SNode[id].Set_All = false;
}

void update(int id, int l, int r, int u, int v, int val, bool Set_All) {
    if (l > v || r < u) return;
    if (u <= l && r <= v) {
        if (Set_All) {
            SNode[id].Set = val;
            SNode[id].Set_All = true;
            SNode[id].increase = 0;
            SNode[id].sum = 1LL * val * (r - l + 1);
        } else {
            SNode[id].increase += val;
            SNode[id].sum += 1LL * val * (r - l + 1);
        }
        return;
    }
    ///
    int mid = (l + r) >> 1;
    down(id, l, mid, r);
    ///
    update(id*2, l, mid, u, v, val, Set_All);
    update(id*2+1, mid+1, r, u, v, val, Set_All);
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
    ///
    scanf("%d%d", &n, &q);
    for(int i=1; i<=n; ++i) {
        int a; scanf("%d", &a);
        update(1, 1, n, i, i, a, true);
    }
    ///
    for(int i=1; i<=q; ++i) {
        int type; scanf("%d", &type);
        int u, v; scanf("%d%d", &u, &v);
        if (type != 3) {
            int val; scanf("%d", &val);
            if (type == 1) update(1, 1, n, u, v, val, false);
            else update(1, 1, n, u, v, val, true);
        } else cout << query(1, 1, n, u, v) << "\n";
    }
    return 0;
}
