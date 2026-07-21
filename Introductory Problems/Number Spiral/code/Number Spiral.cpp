
#include <cstdio>
#include <iostream>
#include <algorithm>
#define llong long long

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

int main() {
    int t; readInt(t);

    while (t--) {
        int x, y; readInt(x), readInt(y);

        llong sum = 1LL * max(x, y) * (max(x, y) - 1) + 1;

        if (x < y) {
            if (y & 1) sum += y - x;
            else sum -= y - x;
        } else {
            if (x & 1) sum -= x - y;
            else sum += x - y;
        }

        writeInt(sum), putchar('\n');
    }

    return 0;
}
