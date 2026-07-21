#include <iostream>
#include <algorithm>

using namespace std;

int bit[1006][1006], a[1006][1006], n, q;
char S[1006];

void update(int x, int y, int val) {
    for(int i=x; i<=n; i += (i & (-i)))
    for(int j=y; j<=n; j += (j & (-j))) bit[i][j] += val;
}

int query(int x, int y) {
    int ans = 0;
    for(int i=x; i>0; i -= (i & (-i)))
    for(int j=y; j>0; j -= (j & (-j))) ans += bit[i][j];
    return ans;
}

int main() {
    ///freopen("inp.txt", "r", stdin);
    ///
    scanf("%d%d", &n, &q);
    for(int i=1; i<=n; ++i) {
        scanf("%s", S+1);
        for(int j=1; j<=n; ++j) {
            a[i][j] = (S[j] == '*');
            update(i, j, a[i][j]);
        }
    }
    ///
    for(int i=1; i<=q; ++i) {
        int type; scanf("%d", &type);
        ///
        if (type == 1) {
            int x, y; scanf("%d%d", &x, &y);
            if (a[x][y]) {
                a[x][y] = 0;
                update(x, y, -1);
            } else {
                a[x][y] = 1;
                update(x, y, 1);
            }
        } else {
            int x, y, u, v; scanf("%d%d%d%d", &x, &y, &u, &v);
            cout << query(u, v) - query(u, y-1) - query(x-1, v) + query(x-1, y-1) << "\n";
        }
    }
    return 0;
}
