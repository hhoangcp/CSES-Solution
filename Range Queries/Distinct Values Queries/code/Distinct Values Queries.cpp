#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#define llong long long

using namespace std;

template<typename T>
bool fast_scan(T &num) {
    num = 0;
    char c = getchar();
    while (c != '-' && (c < '0' || '9' < c)) {
        if (feof(stdin)) return false;
        c = getchar();
    }
    bool neg = false;
    if (c == '-') {
        neg = true;
        c = getchar();
    }
    for(; '0' <= c && c <= '9'; c = getchar()) num = (num << 1) + (num << 3) + (c - '0');
    if (neg) num = -num;
    return true;
}

struct Query {
    int l, r, pos;

    bool operator < (const Query &other) const {
        if (l != other.l) return l < other.l;
        if (r != other.r) return r < other.r;
        return pos < other.pos;
    }
} Q[200006];

int n, m, a[200006], tmp_a[200006], bit[200006];
int res[200006], Next[200006], link[200006];
bool avail[200006];

void update(int u, int val) {
    for(; u<=n; u += (u & (-u))) bit[u] += val;
}

int query(int u) {
    int ans = 0;
    for(; u > 0; u -= (u & (-u))) ans += bit[u];
    return ans;
}

void compress() {
    sort(tmp_a+1, tmp_a+n+1);
    int sz = unique(tmp_a+1, tmp_a+n+1) - tmp_a - 1;
    for(int i=1; i<=n; ++i) a[i] = lower_bound(tmp_a+1, tmp_a+sz+1, a[i]) - tmp_a;
}

int main() {
    ///freopen("inp.txt", "r", stdin);
    ///
    fast_scan(n); fast_scan(m);
    for(int i=1; i<=n; ++i) fast_scan(a[i]), tmp_a[i] = a[i];
    compress();
    ///
    for(int i=n; i>=1; --i) {
        Next[i] = link[a[i]];
        link[a[i]] = i;
    }
    ///
    for(int i=1; i<=n; ++i) {
        if (avail[a[i]]) continue;
        avail[a[i]] = true;
        ///
        update(i, 1);
    }
    ///
    for(int i=1; i<=m; ++i) {
        fast_scan(Q[i].l), fast_scan(Q[i].r);
        Q[i].pos = i;
    }
    ///
    sort(Q+1, Q+m+1);
    int cur = 1;
    for(int i=1; i<=n; ++i) {
        while (cur <= m && Q[cur].l == i) {
            res[Q[cur].pos] = query(Q[cur].r);
            ++cur;
        }
        ///
        if (cur > m) break;
        update(i, -1);
        if (Next[i] > 0) update(Next[i], 1);
    }
    ///
    for(int i=1; i<=m; ++i) cout << res[i] << "\n";
}
