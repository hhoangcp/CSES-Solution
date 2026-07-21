#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
#define ull unsigned long long

using namespace std;

int seg[800006];

void update(int i, int l, int r, int u, int v, int val) {
    if (l > v || r < u) return;
    if (u <= l && r <= v) {
        seg[i] = max(seg[i], val);
        return;
    }

    int mid = (l + r) >> 1;

    update(i * 2 + 1, l, mid, u, v, val);
    update(i * 2 + 2, mid + 1, r, u, v, val);
}

int query(int i, int l, int r, int p) {
    if (l > p || r < p) return 0;
    if (l == r) return seg[i];

    int mid = (l + r) >> 1;

    int ans = seg[i];
    ans = max(ans, query(i * 2 + 1, l, mid, p));
    ans = max(ans, query(i * 2 + 2, mid + 1, r, p));

    return ans;
}

int dp[200006], a[200006], pos[200006], L[200006], R[200006];

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pos[i] = i;
    }

    sort(pos + 1, pos + n + 1, [&] (int i, int j) { return a[i] > a[j]; });

    vector<int> S;
    for (int i = 1; i <= n; ++i) {
        while (!S.empty() && a[S.back()] < a[i]) S.pop_back();
        if (!S.empty()) L[i] = S.back(); else L[i] = 0;
        S.push_back(i);
    }

    S.clear();
    for (int i = n; i >= 1; --i) {
        while (!S.empty() && a[S.back()] < a[i]) S.pop_back();
        if (!S.empty()) R[i] = S.back(); else R[i] = n + 1;
        S.push_back(i);
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int p = pos[i];

        dp[p] = query(0, 1, n, p);
        if (L[p] + 1 <= p - 1) update(0, 1, n, L[p] + 1, p - 1, dp[p] + 1);
        if (p + 1 <= R[p] - 1) update(0, 1, n, p + 1, R[p] - 1, dp[p] + 1);
        ans = max(ans, dp[p]);
    }

    cout << ans + 1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int tests = 1; //cin >> tests;
    for (int i = 0; i < tests; ++i) {
        solve();
    }
}