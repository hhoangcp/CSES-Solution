
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
    int u, v;

    bool operator < (const Data &other) const {
        return v < other.v;
    }
} P[200006];

int n, f[200006];

int main() {
    readInt(n);
    for(int i=1; i<=n; ++i) readInt(P[i].u), readInt(P[i].v);

    sort(P+1, P+n+1);

    for(int i=1; i<=n; ++i) {
        f[i] = f[i-1];

        int l = 1, r = i-1, pos = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (P[mid].v <= P[i].u) {
                pos = mid;
                l = mid + 1;
            } else r = mid - 1;
        }

        f[i] = max(f[i], f[pos] + 1);
    }

    writeInt(f[n]);
    return 0;
}
