
#include <iostream>
#include <algorithm>
#include <queue>
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
    if (num > 9) writeInt(num / 10);
    putchar(num % 10 + '0');
}

int n, x;

int main() {
    readInt(x), readInt(n);
    set<int> S; S.insert(x), S.insert(0);
    multiset<int, greater<int> > T; T.insert(x);

    for(int i=1; i<=n; ++i) {
        int a; readInt(a);

        set<int>::iterator l = --S.lower_bound(a), r = S.upper_bound(a);
        T.erase(T.find(*r - *l));

        S.insert(a); T.insert(*r - a); T.insert(a - *l);

        writeInt(*T.begin()); putchar(' ');
    }

    return 0;
}
