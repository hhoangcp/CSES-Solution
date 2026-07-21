
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int mod = 1e9+7;
int f[10000006], n;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n; f[0] = 1;
    for(int i=1; i<=n; ++i)
    for(int j=i-1; j>=max(0, i-6); --j) f[i] = (f[i] + f[j]) % mod;

    cout << f[n];

    return 0;
}
