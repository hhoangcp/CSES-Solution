
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

int a[200006], n;

int main() {
    readInt(n);
    for(int i=1; i<=n; ++i) readInt(a[i]);

    sort(a+1, a+n+1);

    int t = a[(n + 1) / 2];

    llong res = 0;
    for(int i=1; i<=n; ++i) res += (a[i] > t ? a[i] - t : t - a[i]);

    writeInt(res);
    return 0;
}
