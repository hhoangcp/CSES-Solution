
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

struct Data {
    llong Max, Sum, Left, Right;
} seg[800006];

Data merge(const Data &L, const Data &R) {
    Data C;
    C.Sum = L.Sum + R.Sum;
    C.Left = max(L.Left, L.Sum + R.Left);
    C.Right = max(R.Right, R.Sum + L.Right);
    C.Max = max({L.Max, R.Max, L.Right + R.Left});
    return C;
}

void update(int id, int l, int r, int pos, int val) {
    if (l > pos || r < pos) return;
    if (l == r) {
        seg[id] = {val, val, val, val};
        return;
    }

    int mid = (l + r) >> 1;

    update(id*2+1, l, mid, pos, val);
    update(id*2+2, mid+1, r, pos, val);

    seg[id] = merge(seg[id*2+1], seg[id*2+2]);
}

Data query(int id, int l, int r, int u, int v) {
    if (u > v) return {0, 0, 0, 0};
    if (u == l && r == v) return seg[id];

    int mid = (l + r) >> 1;

    if (v <= mid) return query(id * 2 + 1, l, mid, u, v);
    if (u > mid) return query(id * 2 + 2, mid + 1, r, u, v);
    return merge(query(id * 2 + 1, l, mid, u, mid), query(id * 2 + 2, mid + 1, r, mid + 1, v));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        int a; cin >> a;
        update(0, 1, n, i, a);
    }

    while (m--) {
        int l, r; cin >> l >> r;
        cout << max(0LL, query(0, 1, n, l, r).Max) << '\n';
    }

    return 0;
}
