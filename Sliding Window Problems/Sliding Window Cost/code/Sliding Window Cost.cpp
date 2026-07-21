
#include <iostream>
#include <algorithm>
#include <vector>
#define llong long long

using namespace std;

int n, k, a[200006], Seg[800006];
vector<int> V;

void Compress() {
    for(int i = 1; i <= n; ++i) V.push_back(a[i]);
    sort(V.begin(), V.end());
    for(int i = 1; i <= n; ++i) a[i] = lower_bound(V.begin(), V.end(), a[i]) - V.begin();
}

void Update(int id, int l, int r, int p, int val) {
    if (l > p || r < p) return;
    if (l == r) {
        Seg[id] += val;
        return;
    }

    int mid = (l + r) >> 1;

    Update(id*2+1, l, mid, p, val);
    Update(id*2+2, mid+1, r, p, val);

    Seg[id] = Seg[id*2+1] + Seg[id*2+2];
}

int Find_medium(int id, int l, int r, int pos) {
    if (l > r) return -1;
    if (l == r) return V[l];

    int mid = (l + r) >> 1;
    if (Seg[id*2+1] >= pos) return Find_medium(id*2+1, l, mid, pos);
    return Find_medium(id*2+2, mid+1, r, pos - Seg[id*2+1]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> k;
    for(int i = 1; i <= n; ++i) cin >> a[i];

    Compress();

    for(int i = 1; i <= k; ++i) Update(0, 0, V.size() - 1, a[i], 1);
    int pre = Find_medium(0, 0, V.size() - 1, (k + 1) / 2);

    llong res = 0;
    for(int i = 1; i <= k; ++i) res += abs(V[a[i]] - pre);
    cout << res << ' ';

    for(int i = k + 1; i <= n; ++i) {
        Update(0, 0, V.size() - 1, a[i - k], -1);
        Update(0, 0, V.size() - 1, a[i], 1);

        int now = Find_medium(0, 0, V.size() - 1, (k + 1) / 2);
        res += abs(pre - V[a[i]]) - abs(now - V[a[i - k]]);

        if (!(k & 1)) res += pre - now;
        pre = now;

        cout << res << ' ';
    }

    return 0;
}
