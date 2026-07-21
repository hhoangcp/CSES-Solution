
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

const llong mod = 1e9+7;
llong f[1000006];
int n;

int main() {
    cin >> n;

    f[0] = 1, f[1] = 0;
    for(int i = 2; i <= n; ++i) f[i] = (i - 1) * (f[i - 1] + f[i - 2]) % mod;

    cout << f[n];

    return 0;
}
