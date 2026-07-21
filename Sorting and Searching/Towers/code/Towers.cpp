
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

int n, top[200006], cnt = 0;

int main() {
    readInt(n);
    for(int i=1; i<=n; ++i) {
        int a; readInt(a);

        int l = 1, r = cnt, p = cnt+1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (top[mid] > a) {
                p = mid;
                r = mid - 1;
            } else l = mid + 1;
        }

        cnt = max(cnt, p);
        top[p] = a;
    }

    writeInt(cnt);
    return 0;
}
