#include <iostream>
#include <algorithm>

using namespace std;

int SNode[800006], n, a[200006], leaf[800006];

void build(int id, int l, int r) {
    if (l > r) return;
    if (l == r) {
        leaf[id] = l;
        SNode[id] = 1;
        return;
    }
    ///
    int mid = (l + r) / 2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    ///
    SNode[id] = SNode[id*2] + SNode[id*2+1];
}

void update(int id, int l, int r, int p) {
    if (l > p || r < p) return;
    if (l == r) {
        SNode[id] = 0;
        return;
    }
    ///
    int mid = (l + r) / 2;
    update(id*2, l, mid, p);
    update(id*2+1, mid+1, r, p);
    ///
    SNode[id] = SNode[id*2] + SNode[id*2+1];
}

int query(int id, int pos) {
    if (leaf[id]) return leaf[id];
    ///
    if (SNode[id*2] >= pos) return query(id*2, pos);
    else return query(id*2+1, pos - SNode[id*2]);
}

int main() {
    ///freopen("inp.txt", "r", stdin);
    ///
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    build(1, 1, n);
    ///
    for(int i=1; i<=n; ++i) {
        int p; scanf("%d", &p);
        int pos = query(1, p);
        cout << a[pos] << " ";
        update(1, 1, n, pos);
    }
    return 0;
}
