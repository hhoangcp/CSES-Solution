
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
        return val < other.val;
    }
} P[200006];

int n, x;

int main() {
    readInt(n); readInt(x);
    for(int i=1; i<=n; ++i) readInt(P[i].val), P[i].pos = i;

    sort(P+1, P+n+1);
    for(int i=1, j=n; i<=n && j >= 1; ++i) {
        while (j >= 1 && P[i].val + P[j].val > x) --j;
        if (j > 0 && P[i].val + P[j].val == x && i != j) {
            writeInt(P[i].pos), putchar(' ');
            writeInt(P[j].pos);
            return 0;
        }
    }

    puts("IMPOSSIBLE");
    return 0;
}
