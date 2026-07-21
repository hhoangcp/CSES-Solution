#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

struct Data {
    int x, type, pos;

    bool operator < (const Data &other) const {
        if (x != other.x) return x < other.x;
        return type > other.type;
    }
} P[400006];

int n, ans[200006];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int l, r; cin >> l >> r;
        P[i*2] = {l, 1, i};
        P[i*2+1] = {r, -1, i};
    }

    sort(P, P+2*n);

    stack<int> S;
    while (!S.empty()) S.pop();
    for(int i = n; i >= 1; --i) S.push(i);

    int res = 0;
    for(int i = 0; i < 2 * n; ++i) {
        int type = P[i].type, pos = P[i].pos;

        if (type == 1) ans[pos] = S.top(), S.pop(), res = max(res, ans[pos]);
        else S.push(ans[pos]);
    }

    cout << res << '\n';
    for(int i = 0; i < n; ++i) cout << ans[i] << ' ';

    return 0;
}
