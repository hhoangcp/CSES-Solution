#include <iostream>
#include <algorithm>
#define llong long long
#define _for(i, a, b) for(__typeof(b) i=(a); i<=(b); ++i)

using namespace std;

llong SNode[800006], Lazy[800006];
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

void down(int idx, int low, int middle, int high) {
    Lazy[idx*2] += Lazy[idx];
    Lazy[idx*2+1] += Lazy[idx];
    SNode[idx*2] += Lazy[idx] * (1LL * middle - low + 1);
    SNode[idx*2+1] += Lazy[idx] * (1LL * high - middle);
    Lazy[idx] = 0;
}

void update(int idx, int low, int high, int a, int b, int val) {
    if (low > b || high < a) return;
    if (a <= low && high <= b) {
        SNode[idx] += 1LL * val * (high - low + 1);
        Lazy[idx] += val;
        return;
    }

    int middle = (low + high) / 2;
    down(idx, low, middle, high);

    update(idx*2, low, middle, a, b, val);
    update(idx*2+1, middle+1, high, a, b, val);
    SNode[idx] = SNode[idx*2] + SNode[idx*2+1];
}

llong query(int idx, int low, int high, int a, int b) {
    if (b < low || high < a) return 0;
    if (a <= low && high <= b) return SNode[idx];

    int middle = (low + high) / 2;
    down(idx, low, middle, high);

    return query(idx*2, low, middle, a, b) + query(idx*2+1, middle+1, high, a, b);
}

int main() {
    //freopen("inp.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    fast_scan(n), fast_scan(m);
    _for(i, 1, n) {
        int a; fast_scan(a);
        update(1, 1, n, i, i, a);
    }

    while (m--) {
        int kind; fast_scan(kind);

        if (kind == 1) {
            int a, b, u; fast_scan(a), fast_scan(b), fast_scan(u);
            update(1, 1, n, a, b, u);
        } else {
            int pos; fast_scan(pos);
            cout << query(1, 1, n, pos, pos) << "\n";
        }
    }

    return 0;
}
