
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

template<typename _type_>
void writeInt(_type_ num) {
    if (num > 9) writeInt(num / 10);
    putchar(num % 10 + '0');
}

int main() {
    long long n; scanf("%lld", &n);

    while (n > 1) {
        writeInt(n), putchar(' ');
        if (n & 1) n *= 3, ++n;
        else n >>= 1;
    }

    writeInt(1);
    return 0;
}
