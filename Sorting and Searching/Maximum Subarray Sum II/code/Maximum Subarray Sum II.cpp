
#include <climits>
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

llong Seg[400016], prefix = 0;
int n, a, b;

void Update(int u, llong val) {
    u += n + 1; Seg[u] = val;
    for(u >>= 1; u > 0; u >>= 1) Seg[u] = min(Seg[u<<1], Seg[(u<<1)|1]);
}

llong Query(int l, int r) {
    llong Sum = LLONG_MAX;
    for(l += n + 1, r += n + 1; l < r; l >>= 1, r >>= 1) {
        if ((l & 1) == 1) Sum = min(Sum, Seg[l++]);
        if ((r & 1) == 0) Sum = min(Sum, Seg[r--]);
    }

    if (l == r) Sum = min(Sum, Seg[l]);
    return Sum;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> a >> b;

    Update(1, 0);
    llong res = LLONG_MIN;

    for(int i = 2; i <= n+1; ++i) {
        int x; cin >> x; prefix += x;
        Update(i, prefix);

        if (i > a) {
            llong mmin = Query(max(1, i - b), i - a);
            res = max(res, prefix - mmin);
        }
    }

    cout << res;

    return 0;
}
