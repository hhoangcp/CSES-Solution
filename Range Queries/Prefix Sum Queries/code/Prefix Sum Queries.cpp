
#include <cstdio>
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

llong Max[800006], Lazy[800006];
int n, m, a[200006];

void Down(int id) {
    Lazy[id*2+1] += Lazy[id];
    Lazy[id*2+2] += Lazy[id];

    Max[id*2+1] += Lazy[id];
    Max[id*2+2] += Lazy[id];

    Lazy[id] = 0;
}

void Update(int id, int l, int r, int u, int v, int val) {
    if (l > v || u > r) return;
    if (u <= l && r <= v) {
        Max[id] += val;
        Lazy[id] += val;
        return;
    }

    int mid = (l + r) >> 1;
    Down(id);

    Update(id*2+1, l, mid, u, v, val);
    Update(id*2+2, mid+1, r, u, v, val);

    Max[id] = max(Max[id*2+1], Max[id*2+2]);
}

llong Query(int id, int l, int r, int u, int v) {
    if (l > v || u > r) return -1e18;
    if (u <= l && r <= v) return Max[id];

    int mid = (l + r) >> 1;
    Down(id);

    return max(Query(id*2+1, l, mid, u, v), Query(id*2+2, mid+1, r, u, v));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> m;
    for(int i=1; i<=n; ++i) {
        cin >> a[i];
        Update(0, 0, n, i, n, a[i]);
    }

    while (m--) {
        int type; cin >> type;

        if (type == 1) {
            int k, u; cin >> k >> u;
            Update(0, 0, n, k, n, u - a[k]); a[k] = u;
        } else {
            int u, v; cin >> u >> v;
            cout << Query(0, 0, n, u-1, v) - Query(0, 0, n, u-1, u-1) << '\n';
        }
    }

    return 0;
}
