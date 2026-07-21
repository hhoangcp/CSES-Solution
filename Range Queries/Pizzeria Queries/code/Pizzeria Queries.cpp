
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Segment_Tree {
    int N;
    vector<int> Min;

    Segment_Tree(int n) {
        N = n;
        Min.assign(4*n+1, 0);
    }

    void Update(int id, int l, int r, int p, int val) {
        if (l > p || r < p) return;
        if (l == r) {
            Min[id] = val;
            return;
        }

        int mid = (l + r) >> 1;

        Update(id*2+1, l, mid, p, val);
        Update(id*2+2, mid+1, r, p, val);

        Min[id] = min(Min[id*2+1], Min[id*2+2]);
    }

    int Query(int id, int l, int r, int u, int v) {
        if (u > r || l > v) return 1e9+1e6;
        if (u <= l && r <= v) return Min[id];

        int mid = (l + r) >> 1;
        return min(Query(id*2+1, l, mid, u, v), Query(id*2+2, mid+1, r, u, v));
    }

    void Update(int k, int x) {
        Update(0, 1, N, k, x);
    }

    int Query(int u, int v) {
        return Query(0, 1, N, u, v);
    }
};

int n, m;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> m;
    Segment_Tree Down = Segment_Tree(n), Up = Segment_Tree(n);

    for(int i=1; i<=n; ++i) {
        int p; cin >> p;
        Down.Update(i, p - i);
        Up.Update(i, p + i);
    }

    while (m--) {
        int type; cin >> type;

        if (type == 1) {
            int k, x; cin >> k >> x;
            Down.Update(k, x - k);
            Up.Update(k, x + k);
        } else {
            int k; cin >> k;
            cout << min(Down.Query(1, k) + k, Up.Query(k, n) - k) << '\n';
        }
    }

    return 0;
}
