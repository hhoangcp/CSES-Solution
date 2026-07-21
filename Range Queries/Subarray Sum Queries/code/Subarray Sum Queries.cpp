#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

struct Data {
    llong Sum, Max, Left, Right;
} SNode[800006];

int n, q;

void update_node(int id) {
    SNode[id].Sum = SNode[id*2].Sum + SNode[id*2+1].Sum;
    SNode[id].Left = max(SNode[id*2].Left, SNode[id*2].Sum + SNode[id*2+1].Left);
    SNode[id].Right = max(SNode[id*2+1].Right, SNode[id*2+1].Sum + SNode[id*2].Right);
    SNode[id].Max = max(max(SNode[id*2].Max, SNode[id*2+1].Max), SNode[id*2].Right + SNode[id*2+1].Left);
}

void update(int id, int l, int r, int p, int val) {
    if (l > p || r < p) return;
    ///
    if (l == r) {
        SNode[id] = {val, val, val, val};
        return;
    }
    ///
    int mid = (l + r) / 2;
    update(id*2, l, mid, p, val);
    update(id*2+1, mid+1, r, p, val);
    ///
    update_node(id);
}

int main() {
    ///freopen("inp.txt", "r", stdin);
    ///
    scanf("%d%d", &n, &q);
    for(int i=1; i<=n; ++i) {
        int a; scanf("%d", &a);
        update(1, 1, n, i, a);
    }
    ///
    for(int i=1; i<=q; ++i) {
        int p, val; scanf("%d%d", &p, &val);
        update(1, 1, n, p, val);
        cout << max(0LL, SNode[1].Max) << "\n";
    }
    return 0;
}
