#include <iostream>
#include <algorithm>

using namespace std;

int SNode[800006], n, m, a[200006];
int leaf[800006];

void build(int id, int l, int r) {
    if (l > r) return;
    if (l == r) {
        leaf[id] = l;
        SNode[id] = a[l];
        return;
    }
    ///
    int mid = (l + r) / 2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    ///
    SNode[id] = max(SNode[id*2], SNode[id*2+1]);
}

void update(int id, int l, int r, int p, int val) {
    if (l > p || r < p) return;
    if (l == r) {
        SNode[id] += val;
        return;
    }
    ///
    int mid = (l + r) / 2;
    update(id*2, l, mid, p, val);
    update(id*2+1, mid+1, r, p, val);
    ///
    SNode[id] = max(SNode[id*2], SNode[id*2+1]);
}

int query(int id, int val) {
    if (leaf[id]) {
        if (SNode[id] >= val) return leaf[id];
        else return 0;
    }
    ///
    if (SNode[id*2] >= val) return query(id*2, val);
    else if (SNode[id*2+1] >= val) return query(id*2+1, val);
    return 0;
}

int main() {
    ///freopen("inp.txt", "r", stdin);
    ///
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    ///
    build(1, 1, n);
    for(int i=1; i<=m; ++i) {
        int x; scanf("%d", &x);
        int pos = query(1, x);
        cout << pos << " ";
        if (pos > 0) update(1, 1, n, pos, -x);
    }
    return 0;
}
