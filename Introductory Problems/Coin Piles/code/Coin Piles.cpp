
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

int main() {
    int n; readInt(n);

    while (n--) {
        long long a, b; readInt(a), readInt(b);
        long long a2 = a * 2 - b;
        if (a2 < 0 || a2 % 3) puts("NO");
        else {
            long long y = a2 / 3;
            if (y > b || (b - y) % 2) puts("NO");
            else puts("YES");
        }
    }

    return 0;
}
