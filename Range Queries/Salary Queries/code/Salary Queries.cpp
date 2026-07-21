#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

struct Query {
    int type, pos, val;
    int a, b;
} Q[200006];

int bit[800006], a[200006], sz, n, q;
set<int> x;

void compress() {
    vector<int> A(x.begin(), x.end()); sz = A.size();
    ///
    for(int i=1; i<=n; ++i) a[i] = lower_bound(A.begin(), A.end(), a[i]) - A.begin() + 1;
    for(int i=1; i<=n; ++i)
    if (Q[i].type == 1) Q[i].val = lower_bound(A.begin(), A.end(), Q[i].val) - A.begin() + 1;
    else {
        Q[i].a = lower_bound(A.begin(), A.end(), Q[i].a) - A.begin() + 1;
        Q[i].b = lower_bound(A.begin(), A.end(), Q[i].b) - A.begin() + 1;
    }
}

void update(int p, int val) {
    for(; p <= sz; p += (p & (-p))) bit[p] += val;
}

int query(int p) {
    int ans = 0;
    for(; p > 0; p -= (p & (-p))) ans += bit[p];
    return ans;
}

char in[2];

int main() {
    ///freopen("inp.txt", "r", stdin);
    ///
    scanf("%d%d", &n, &q);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]), x.insert(a[i]);
    for(int i=1; i<=q; ++i) {
        scanf("%s", in+1);
        if (in[1] == '!') Q[i].type = 1; else Q[i].type = 0;
        ///
        if (Q[i].type == 1) {
            scanf("%d%d", &Q[i].pos, &Q[i].val);
            x.insert(Q[i].val);
        } else {
            scanf("%d%d", &Q[i].a, &Q[i].b);
            x.insert(Q[i].a);
            x.insert(Q[i].b);
        }
    }
    ///
    compress();
    ///
    for(int i=1; i<=n; ++i) update(a[i], 1);
    for(int i=1; i<=q; ++i)
    if (Q[i].type == 1) {
        update(a[Q[i].pos], -1);
        update(Q[i].val, 1);
        a[Q[i].pos] = Q[i].val;
    } else cout << query(Q[i].b) - query(Q[i].a-1) << "\n";
    return 0;
}
