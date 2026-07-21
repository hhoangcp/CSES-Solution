#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <climits>
#define ll long long
#define ull unsigned long long

using namespace std;

set<int> S[400006];

struct Data {
    int kind, p, val, l, r;
} Q[200006];

int seg[800006], a[200006], init[200006], sorted[400006], sz = 0;

int prev(int val, int k) {
    set<int>::iterator it = S[val].lower_bound(k);
    if (it == S[val].begin()) return 0;
    return *prev(it);
}

int next(int val, int k) {
    set<int>::iterator it = S[val].upper_bound(k);
    if (it == S[val].end()) return 0;
    return *it;
}

void build(int i, int l, int r) {
    if (l > r) return;
    if (l == r) {
        seg[i] = init[l];
        return;
    }

    int mid = (l + r) >> 1;
    build(i * 2 + 1, l, mid);
    build(i * 2 + 2, mid + 1, r);

    seg[i] = min(seg[i * 2 + 1], seg[i * 2 + 2]);
}

void update(int i, int l, int r, int p, int val) {
    if (l > p || r < p) return;
    if (l == r) {
        seg[i] = val;
        return;
    }

    int mid = (l + r) >> 1;
    update(i * 2 + 1, l, mid, p, val);
    update(i * 2 + 2, mid + 1, r, p, val);

    seg[i] = min(seg[i * 2 + 1], seg[i * 2 + 2]);
}

int query(int i, int l, int r, int u, int v) {
    if (l > v || r < u) return INT_MAX;
    if (u <= l && r <= v) return seg[i];

    int mid = (l + r) >> 1;
    return min(query(i * 2 + 1, l, mid, u, v), query(i * 2 + 2, mid + 1, r, u, v));
}

void solve() {
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sorted[++sz] = a[i];
    }

    for (int i = 1; i <= q; ++i) {
        int kind; cin >> kind;
        if (kind == 1) {
            int p, val; cin >> p >> val;
            sorted[++sz] = val;
            Q[i] = { kind, p, val, -1, -1 };
        } else {
            int l, r; cin >> l >> r;
            Q[i] = { kind, -1, -1, l, r};
        }
    }

    sort(sorted + 1, sorted + sz + 1);
    sz = unique(sorted + 1, sorted + sz + 1) - sorted - 1;

    for (int i = n; i >= 1; --i) {
        a[i] = lower_bound(sorted + 1, sorted + sz + 1, a[i]) - sorted;
        if (S[a[i]].empty()) init[i] = n + 1; else init[i] = *S[a[i]].begin();
        S[a[i]].insert(i);
    }

    build(0, 1, n);

    for (int i = 1; i <= q; ++i) {
        int kind = Q[i].kind;
        if (kind == 1) {
            int p = Q[i].p, &val = Q[i].val;
            val = lower_bound(sorted + 1, sorted + sz + 1, val) - sorted;

            S[a[p]].erase(p);
            int l = prev(a[p], p), r = next(a[p], p);
            if (l != 0) {
                if (r == 0) r = n + 1;
                update(0, 1, n, l, r);
            }

            l = prev(val, p), r = next(val, p);
            S[val].insert(p);
            if (l != 0) update(0, 1, n, l, p);
            if (r == 0) r = n + 1;
            update(0, 1, n, p, r);

            a[p] = val;
        } else {
            int l = Q[i].l, r = Q[i].r;
            if (query(0, 1, n, l, r) <= r) cout << "NO\n";
            else cout << "YES\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int tests = 1; //cin >> tests;
    for (int i = 0; i < tests; ++i) {
        solve();
    }
}