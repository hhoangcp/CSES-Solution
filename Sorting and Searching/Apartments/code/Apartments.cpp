
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

int n, m, a[200006], b[200006], k;

int main() {
    readInt(n), readInt(m), readInt(k);
    for(int i=1; i<=n; ++i) readInt(a[i]);
    for(int i=1; i<=m; ++i) readInt(b[i]);

    int res = 0;
    sort(a+1, a+n+1);
    sort(b+1, b+m+1);

    for(int i=1, j=1; i<=n && j<=m; ++i) {
        while (j<=m && a[i] - b[j] > k) ++j;
        if (j <= m && abs(a[i] - b[j]) <= k) ++res, ++j;
    }

    cout << res;
    return 0;
}
