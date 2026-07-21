
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

int n, x, a[200006];
bool avail[200006];

int main() {
    readInt(n), readInt(x);
    for(int i=1; i<=n; ++i) readInt(a[i]);

    int res = 0;
    sort(a+1, a+n+1);

    for(int i=1, p = n; i<=n; ++i)
    if (!avail[i]) {
        ++res;
        avail[i] = true;
        while (p >= i && a[p] + a[i] > x) --p;
        if (p > i) avail[p] = true; --p;
    }

    cout << res;
    return 0;
}
