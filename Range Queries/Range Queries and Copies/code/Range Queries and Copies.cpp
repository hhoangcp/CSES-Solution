#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

typedef struct Data {
    Data *Left, *Right;
    llong sum;
} *node;

node ver[200006];
int n, q, a[200006];

node new_node() {
    node P = new Data();
    P->Left = P->Right = NULL;
    P->sum = 0;
    return P;
}

void build(node &root, int l, int r) {
    if (l > r) return;
    root = new_node();
    if (l == r) {
        root->sum = a[l];
        return;
    }
    ///
    int mid = (l + r) >> 1;
    build(root->Left, l, mid);
    build(root->Right, mid+1, r);
    ///
    root->sum = root->Left->sum + root->Right->sum;
}


void update(node &root, node old_root, int l, int r, int p, int val) {
    if (l > p || r < p) return;
    root = new_node();
    if (l == r) {
        root->sum += val;
        return;
    }
    ///
    int mid = (l + r) >> 1;
    if (p <= mid) {
        root->Right = old_root->Right;
        update(root->Left, old_root->Left, l, mid, p, val);
    } else {
        root->Left = old_root->Left;
        update(root->Right, old_root->Right, mid+1, r, p, val);
    }
    ///
    root->sum = root->Left->sum + root->Right->sum;
}

llong query(node root, int l, int r, int u, int v) {
    if (v < l || r < u) return 0LL;
    if (u <= l && r <= v) return root->sum;
    ///
    int mid = (l + r) >> 1;
    return query(root->Left, l, mid, u, v) + query(root->Right, mid+1, r, u, v);
}

int main() {
    ///freopen("inp.txt", "r", stdin);
    ///freopen("out.txt", "w", stdout);
    ///
    scanf("%d%d", &n, &q);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    build(ver[1], 1, n);
    ///
    int cur_version = 1;
    for(int i=1; i<=q; ++i) {
        int type, version; scanf("%d%d", &type, &version);
        if (type == 1) {
            int p, val; scanf("%d%d", &p, &val);
            node new_root = new_node();
            update(new_root, ver[version], 1, n, p, val);
            ver[version] = new_root;
        } else if (type == 2) {
            int u, v; scanf("%d%d", &u, &v);
            cout << query(ver[version], 1, n, u, v) << "\n";
        } else ver[++cur_version] = ver[version];
    }
    return 0;
}
