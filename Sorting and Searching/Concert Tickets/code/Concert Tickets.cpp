
#include <iostream>
#include <algorithm>
#include <set>

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

int n, m;
multiset<int> S;

int main() {
    readInt(n), readInt(m);

    for(int i=1; i<=n; ++i) {
        int a; readInt(a);
        S.insert(a);
    }

    for(int i=1; i<=m; ++i) {
        int b; readInt(b);

        if (S.empty()) writeInt(-1);
        else {
            auto it = S.upper_bound(b);
            if (it == S.begin()) writeInt(-1);
            else {
                writeInt(*(--it));
                S.erase(it);
            }
        }
        putchar('\n');
    }

    return 0;
}
