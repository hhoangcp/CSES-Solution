#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

struct Point {
    int x, y;
    llong val;

    bool operator < (const Point &other) const {
        return x < other.x || (x == other.x && y < other.y);
    }
} P[2006];

const llong mod = 1e9+7;
llong fact[2000006], inv[2000006];
int n, m;

void init() {
    fact[0] = fact[1] = inv[0] = inv[1] = 1;

    for(int i = 2; i <= 2*n; ++i) {
        fact[i] = fact[i-1] * i % mod;
        inv[i] = mod - ((mod / i) * inv[mod % i] % mod);
    }

    for(int i = 2; i <= 2*n; ++i) (inv[i] *= inv[i-1]) %= mod;
}

llong get_C(int X, int p) {
    return ((fact[X] * inv[p]) % mod * inv[X-p]) % mod;
}

void process(int pos, int x, int y, llong &res) {
    int m1 = n-x+1, n1 = n-y+1;
    llong tmp = get_C(x+y-2, x-1);

    for(int i=1; i<pos; ++i)
    if (P[i].y <= y) {
        int u = x - P[i].x + 1, v = y - P[i].y + 1;
        llong tmp1 = get_C(u+v-2, u-1);
        tmp1 *= P[i].val; tmp1 %= mod;
        tmp = (tmp - tmp1 + mod) % mod;
    }

    P[pos].val = tmp;
    if (m1 == 1 && n1 == 1) res = (res - tmp + mod) % mod;
    else {
        llong tmp1 = get_C(m1+n1-2, m1-1);
        tmp *= tmp1; tmp %= mod;
        res = (res - tmp + mod) % mod;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> m;
    if (n == 1) {
        if (m == 0) cout << 1;
        else cout << 0;
        return 0;
    }

    init();
    llong res = get_C(2*n-2, n-1);

    for(int i = 1; i <= m; ++i) {
        cin >> P[i].x >> P[i].y;

        if (P[i].x == 1 && P[i].y == 1) return cout << 0, 0;
        if (P[i].x == n && P[i].y == n) return cout << 0, 0;

        else P[i].val = get_C(P[i].x+P[i].y - 2, P[i].x - 1);
    }

    sort(P+1, P+m+1);
    for(int i = 1; i <= m; ++i) process(i, P[i].x, P[i].y, res);

    cout << res;

    return 0;
}
