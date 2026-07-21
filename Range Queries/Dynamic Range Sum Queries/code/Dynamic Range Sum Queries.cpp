#include <iostream>
#include <algorithm>
#define llong long long
#define _for(i, a, b) for(__typeof(b) i=(a); i<=(b); ++i)

using namespace std;

llong SNode[800006];
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

void update(int idx, int low, int high, int pos, int val) {
    if (low > pos || high < pos) return;
    if (low == high) {
        SNode[idx] = val;
        return;
    }

    int middle = (low + high) / 2;
    update(idx*2, low, middle, pos, val);
    update(idx*2+1, middle+1, high, pos, val);
    SNode[idx] = SNode[idx*2] + SNode[idx*2+1];
}

llong query(int idx, int low, int high, int a, int b) {
    if (b < low || high < a) return 0;
    if (a <= low && high <= b) return SNode[idx];

    int middle = (low + high) / 2;
    return query(idx*2, low, middle, a, b) + query(idx*2+1, middle+1, high, a, b);
}

int main() {
    //freopen("inp.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    fast_scan(n), fast_scan(m);
    _for(i, 1, n) {
        int a; fast_scan(a);
        update(1, 1, n, i, a);
    }

    while (m--) {
        int kind; fast_scan(kind);

        if (kind == 1) {
            int k, u; fast_scan(k), fast_scan(u);
            update(1, 1, n, k, u);
        } else {
            int a, b; fast_scan(a), fast_scan(b);
            cout << query(1, 1, n, a, b) << "\n";
        }
    }

    return 0;
}
