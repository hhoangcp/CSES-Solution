
#include <cstdio>
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

template<typename _type_>
void writeInt(_type_ num) {
    if (num > 9) writeInt(num / 10);
    putchar(num % 10 + '0');
}

using namespace std;

int main() {
    int n; scanf("%d", &n);

    if (n == 1) puts("1");
    else if (n <= 3) puts("NO SOLUTION");
    else {
        for(int i = n - (1 - n % 2); i >= 1; i -= 2) writeInt(i), putchar(' ');
        for(int i = n - n % 2; i >= 2; i -= 2) writeInt(i), putchar(' ');
    }

    return 0;
}
