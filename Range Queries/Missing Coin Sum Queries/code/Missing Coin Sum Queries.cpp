
#include <iostream>
#include <algorithm>
#include <vector>
#define llong long long

using namespace std;

struct query {
    int l, r;
} Q[200006];

vector<int> check[200006];
llong bit[200006], ans[200006];
int n, q, a[200006], pos[200006], sorted[200006];

void Update(int p, int val) {
    for(; p <= n; p += (p & (-p))) bit[p] += val;
}

llong Query(int p) {
    llong sum = 0;
    for(; p > 0; p -= (p & (-p))) sum += bit[p];
    return sum;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> q;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        pos[i] = i;
    }

    sort(pos+1, pos+n+1, [] (const int &A, const int &B) {
        return a[A] < a[B];
    });

    for(int i = 1; i <= n; ++i) sorted[i] = a[pos[i]];
    for(int i = 1; i <= q; ++i) {
        int l, r; cin >> l >> r;
        Q[i] = {l, r};
        check[0].push_back(i);
    }

    for(int i = 0; i <= n; ++i) {
        if (i > 0) Update(pos[i], sorted[i]);

        for(int cur: check[i]) {
            ans[cur] = Query(Q[cur].r) - Query(Q[cur].l - 1) + 1;
            int p = upper_bound(sorted + 1, sorted + n + 1, ans[cur]) - sorted - 1;
            if (p > i) check[p].push_back(cur);
        }
    }

    for(int i = 1; i <= q; ++i) cout << ans[i] << '\n';
    return 0;
}

