
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

int n;
llong res = 0;

int main() {
    readInt(n);

    int pre = 0;
    for(int i=1; i<=n; ++i) {
        int now; readInt(now);

        if (pre > now) res += pre - now, now = pre;
        pre = now;
    }

    writeInt(res);
    return 0;
}
