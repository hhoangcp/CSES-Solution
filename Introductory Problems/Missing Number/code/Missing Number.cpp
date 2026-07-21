
#include <cstdio>
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

int n;
int a[200006];

int main() {
    readInt(n);
    for(int i=1; i<n; ++i) {
        int x; readInt(x);
        ++a[x];
    }

    for(int i=1; i<=n; ++i)
    if (!a[i]) {
        writeInt(i);
        return 0;
    }

    return 0;
}
