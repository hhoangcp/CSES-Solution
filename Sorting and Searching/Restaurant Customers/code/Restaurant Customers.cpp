
#include <iostream>
#include <algorithm>

using namespace std;

template<typename _type_>
void readInt(_type_ &num) {
    char c = getchar();
    while (c != '-' && ('0' > c || c > '9')) c = getchar();
    bool neg = false;
    if (c == '-') neg = true, c = getchar();
    for(num = 0; '0' <= c && c <= '9'; c = getchar()) num = (num << 1) + (num << 3) + (c - '0');
    if (neg) num = -num;
}

template<typename _type_>
void writeInt(_type_ num) {
    if (num > 9) writeInt(num / 10);
    putchar(num % 10 + '0');
}

struct Data {
    int val, pos;

    bool operator < (const Data &other) const {
        return pos < other.pos || (pos == other.pos && val > other.val);
    }
} P[4000006];

int n;

int main() {
    readInt(n);
    for(int i=1; i<=n; ++i) {
        int x, y; readInt(x), readInt(y);
        P[i] = {1, x};
        P[i+n] = {-1, y};
    }

    sort(P+1, P+2*n+1);

    int res = 0, cnt = 0;
    for(int i=1; i<=2*n; ++i) {
        cnt += P[i].val;
        res = max(res, cnt);
    }

    writeInt(res);
    return 0;
}
