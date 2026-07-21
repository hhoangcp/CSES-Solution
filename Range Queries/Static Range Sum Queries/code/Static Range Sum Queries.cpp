#pragma GCC optimize("O2")
#include <iostream>
#include <algorithm>
#define llong long long
#define _for(i, a, b) for(__typeof(b) i=(a); i<=(b); ++i)

using namespace std;

llong S[200006];
int n, m;

template<typename T>
bool fast_scan(T &num) {
    num = 0;
    char c = getchar();
    while (c != '-' && (c < '0' || '9' < c)) {
        if (feof(stdin)) return false;
        c = getchar();
    }
    bool neg = false;
    if (c == '-') {
        neg = true;
        c = getchar();
    }
    for(; '0' <= c && c <= '9'; c = getchar()) num = (num << 1) + (num << 3) + (c - '0');
    if (neg) num = -num;
    return true;
}

int main() {
    //freopen("inp.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    fast_scan(n); fast_scan(m);
    _for(i, 1, n) {
        int a; fast_scan(a);
        S[i] = S[i-1] + a;
    }

    while (m--) {
        int u, v; fast_scan(u), fast_scan(v);
        cout << S[v] - S[u-1] << "\n";
    }
    return 0;
}
