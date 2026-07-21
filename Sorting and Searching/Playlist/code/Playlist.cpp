
#include <iostream>
#include <algorithm>
#include <map>

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

map<int, int> Cnt;
int n, res = 0, a[200006];

int main() {
    readInt(n);
    for(int i=1, l=1; i<=n; ++i) {
        readInt(a[i]);
        ++Cnt[a[i]];

        while (Cnt[a[i]] > 1) --Cnt[a[l++]];
        res = max(res, i - l + 1);
    }

    writeInt(res);
    return 0;
}
