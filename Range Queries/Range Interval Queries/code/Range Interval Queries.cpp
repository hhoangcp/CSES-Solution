#include <algorithm>
#include <iostream>
#define ll long long
#define ull unsigned long long

using namespace std;

int root[200006], curr = 0;
int seg[6600006], L[6600006], R[6600006];

void update(int old, int now, int l, int r, int p, int val) {
    if (l > p || r < p) return;
    if (l == r) {
        seg[now] = seg[old] + val;
        return;
    }

    int mid = (l + r) >> 1;
    if (p <= mid) {
        R[now] = R[old];
        L[now] = ++curr;
        update(L[old], L[now], l, mid, p, val);
    } else {
        L[now] = L[old];
        R[now] = ++curr;
        update(R[old], R[now], mid + 1, r, p, val);
    }

    seg[now] = seg[L[now]] + seg[R[now]];
}

int query(int old, int now, int l, int r, int u, int v) {
    if (l > v || r < u) return 0;
    if (u <= l && r <= v) return seg[now] - seg[old];

    int mid = (l + r) >> 1;
    return query(L[old], L[now], l, mid, u, v) + query(R[old], R[now], mid + 1, r, u, v);
}

void solve() {
    int n, q; cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        root[i] = ++curr;
        int x; cin >> x;
        update(root[i - 1], root[i], 1, 1'000'000'000, x, 1);
    }

    while (q--) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        cout << query(root[a - 1], root[b], 1, 1'000'000'000, c, d) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int tests = 1; //cin >> tests;
    for (int i = 0; i < tests; ++i) {
        solve();
    }
}