
#include <cstdio>
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

const llong mod = 1e9+8277;
llong power[200006], inv[200006], bit[2][200006];
int n, q;
char S[200006], inp[4];

void Update(int u, char c) {
    llong val1 = ((c - S[u] + mod) % mod * power[n-u]) % mod;
    llong val2 = ((c - S[u] + mod) % mod * power[u-1]) % mod;

    for(int p = u; p <= n; p += (p & (-p))) (bit[0][p] += val1) %= mod;
    for(int p = n-u+1; p <= n; p += (p & (-p))) (bit[1][p] += val2) %= mod;

    S[u] = c;
}

llong Query_Hash(int block, int p) {
    llong sum = 0;
    for(; p > 0; p -= (p & (-p))) (sum += bit[block][p]) %= mod;
    return sum;
}

bool Checking(int l, int r) {
    llong Hash1 = (Query_Hash(0, r) - Query_Hash(0, l-1) + mod * mod) % mod;
    llong Hash2 = (Query_Hash(1, n-l+1) - Query_Hash(1, n-r) + mod * mod) % mod;

    Hash1 = (Hash1 * inv[n-r]) % mod;
    Hash2 = (Hash2 * inv[l-1]) % mod;

    return Hash1 == Hash2;
}

void Init() {
    power[0] = inv[0] = 1;

    for(int i = 1; i <= n; ++i) {
        power[i] = power[i-1] * 31 % mod;
        inv[i] = inv[i-1] * 935491614 % mod;
    }

    for(int i = 1; i <= n; ++i) {
        char c = S[i]; S[i] = char('a' - 1);
        Update(i, c);
    }
}

int main() {
    scanf("%d%d", &n, &q);
    scanf("%s", S+1);

    Init();
    while (q--) {
        int type; scanf("%d", &type);

        if (type == 1) {
            int x; scanf("%d%s", &x, inp);
            Update(x, inp[0]);
        } else {
            int l, r; scanf("%d%d", &l, &r);
            bool ans = Checking(l, r);

            if (ans) puts("YES");
            else puts("NO");
        }
    }

    return 0;
}
