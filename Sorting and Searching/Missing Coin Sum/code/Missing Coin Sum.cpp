
#include <cstdio>
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

int n, a[200006];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];

    sort(a+1, a+n+1);

    llong cur = 0;
    for(int i=1; i<=n; cur += a[i++])
    if (cur + 1 < a[i]) break;

    cout << cur + 1;

    return 0;
}
