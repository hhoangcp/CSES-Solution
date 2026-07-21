
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;


set<int> S;
int n;

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
    readInt(n);
    for(int i=1; i<=n; ++i) {
        int a; readInt(a);
        S.insert(a);
    }

    cout << S.size();
    return 0;
}
