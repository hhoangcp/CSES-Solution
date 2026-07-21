
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Segment_Tree {
    vector<int> Seg, Lazy;

    Segment_Tree(int n) {
        Seg.assign(4*n+1, 0);
        Lazy.assign(4*n+1, 0);
    }

    void Down(int id) {
        Lazy[id*2+1] += Lazy[id];
        Lazy[id*2+2] += Lazy[id];
        Seg[id*2+1] += Lazy[id];
        Seg[id*2+2] += Lazy[id];
        Lazy[id] = 0;
    }

    void Update(int id, int l, int r, int u, int v, int val) {
        if (l > v || r < u) return;
        if (u <= l && r <= v) {
            Seg[id] += val;
            Lazy[id] += val;
            return;
        }

        int mid = (l + r) >> 1;
        Down(id);

        Update(id*2+1, l, mid, u, v, val);
        Update(id*2+2, mid+1, r, u, v, val);

        Seg[id] = min(Seg[id*2+1], Seg[id*2+2]);
    }

    int Query_Root() {
        return Seg[0];
    }
};

int n;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;

    Segment_Tree Stack_1 = Segment_Tree(n), Stack_2 = Segment_Tree(n);
    for(int i = 1; i <= n; ++i) {
        int c, s; cin >> c >> s;
        if (s == 1) {
            Stack_1.Update(0, 1, n, 1, c, 1);
            Stack_2.Update(0, 1, n, 1, c, -1);
        } else {
            Stack_1.Update(0, 1, n, 1, c, -1);
            Stack_2.Update(0, 1, n, 1, c, 1);
        }

        if (Stack_1.Query_Root() >= 0) cout << ">\n";
        else if (Stack_2.Query_Root() >= 0) cout << "<\n";
        else cout << "?\n";
    }

    return 0;
}
