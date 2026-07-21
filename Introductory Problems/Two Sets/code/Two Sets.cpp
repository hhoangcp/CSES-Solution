
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

int main() {
    int n; scanf("%d", &n);

    llong sum = 1LL * n * (n + 1) / 2;
    if (sum & 1) {
        puts("NO");
        return 0;
    }

    puts("YES"); sum /= 2;

    llong sum_t = 0, sz = 0;
    for(int i=1; i<=n && sum_t < sum; ++i) ++sz, sum_t += i;

    int pos = sum_t - sum;

    writeInt(sz - (pos > 0)), putchar('\n');
    for(int i=1; i<=sz; ++i)
    if (i != pos) writeInt(i), putchar(' ');

    putchar('\n');

    writeInt(n - sz + (pos > 0)); putchar('\n');
    for(int i=n; i > sz; --i) writeInt(i), putchar(' ');
    if (pos > 0) writeInt(pos);

    return 0;
}
