
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

int n, mmax = 0;
llong sum = 0;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; ++i) {
        int a; cin >> a;
        mmax = max(mmax, a);
        sum += a;
    }

    cout << max(2LL * mmax, sum);

    return 0;
}
