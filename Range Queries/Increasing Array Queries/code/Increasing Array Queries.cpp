
#include <cstdio>
#include <climits>
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#define llong long long

using namespace std;

llong bit[200006], pre[200006], delta[200006], res[200006];
int n, m, x[200006];
vector<pair<int, int> > R[200006];

void Update(int u, llong val) {
    for(; u <= n; u += (u & (-u))) bit[u] += val;
}

llong Query(int u) {
    llong sum = 0;
    for(; u > 0; u -= (u & (-u))) sum += bit[u];
    return sum;
}

llong Query(int u, int v) {
    return Query(v) - Query(u-1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> m;
    for(int i=1; i<=n; ++i) {
        cin >> x[i];
        pre[i] = pre[i-1] + x[i];
    }

    for(int i=1; i<=m; ++i) {
        int a, b; cin >> a >> b;
        R[a].push_back({b, i});
    }

    x[n+1] = INT_MAX;

    deque<int> Stack; Stack.push_front(n+1);
    for(int i=n; i>=1; --i) {
        while (!Stack.empty() && x[i] >= x[Stack.front()]) {
            Update(Stack.front(), -delta[Stack.front()]);
            Stack.pop_front();
        }

        delta[i] = (1LL * Stack.front() - i - 1) * x[i] - (pre[Stack.front() - 1] - pre[i]);
        Stack.push_front(i);
        Update(i, delta[i]);

        for(pair<int, int> query: R[i]) {
            int p = upper_bound(Stack.begin(), Stack.end(), query.first) - Stack.begin() - 1;
            res[query.second] = (p > 0 ? Query(i, Stack[p - 1]) : 0) + (1LL * query.first - Stack[p]) * x[Stack[p]] - (pre[query.first] - pre[Stack[p]]);
        }
    }

    for(int i=1; i<=m; ++i) cout << res[i] << '\n';

    return 0;
}
