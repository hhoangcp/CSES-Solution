
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
    if (num < 0) {
        putchar('-');
        writeInt(-num);
        return;
    }
    if (num > 9) writeInt(num / 10);
    putchar(num % 10 + '0');
}

int n;

int main() {
    readInt(n);

    llong S = 0, res = -1e18, h = 0;
    for(int i=1; i<=n; ++i) {
        int a; readInt(a);
        S += a;

        res = max(res, S - h);
        h = min(h, S);
    }

    writeInt(res);
    return 0;
}
