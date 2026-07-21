
#include <iostream>
#include <algorithm>

using namespace std;

struct Data {
    int l, r, pos;

    bool operator < (const Data &other) const {
        if (r != other.r) return r < other.r;
        return l > other.l;
    }
} D[200006];

int n, L[200006], bit[200006], sz_l = 0;
int ans[2][200006];

void add(int p) {
    for(; p <= sz_l; p += (p & (-p))) ++bit[p];
}

int query(int p) {
    int sum = 0;
    for(; p > 0; p -= (p & (-p))) sum += bit[p];
    return sum;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; ++i) {
        int l, r; cin >> l >> r;
        L[sz_l++] = l;
        D[i] = {l, r, i};
    }

    sort(D, D+n);
    sort(L, L+sz_l);
    sz_l = unique(L, L+sz_l) - L;

    for(int i = 0; i < n; ++i) {
        D[i].l = lower_bound(L, L+sz_l, D[i].l) - L + 1;
        ans[0][D[i].pos] = i - query(D[i].l - 1);
        add(D[i].l);
    }

    for(int i = 1; i <= sz_l; ++i) bit[i] = 0;

    for(int i = n - 1; i >= 0; --i) {
        ans[1][D[i].pos] = query(D[i].l);
        add(D[i].l);
    }

    for(int i = 0; i < n; ++i) cout << ans[0][i] << ' ';
    cout << '\n';
    for(int i = 0; i < n; ++i) cout << ans[1][i] << ' ';

    return 0;
}
