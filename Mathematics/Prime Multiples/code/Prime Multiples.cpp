
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

const llong MAX = 1e18;
llong n, a[26];
int k;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> k;
    for(int i = 1; i <= k; ++i) cin >> a[i];

    llong res = 0;
    for(int i = 1; i < (1 << k); ++i) {
        llong mul = 1;
        bool ok = true;
        int del = -1;

        for(int j = 0; j < k; ++j)
        if (i & (1 << j)) {
            if (mul > MAX / a[j+1]) {
                ok = false;
                break;
            }

            mul *= a[j+1];
            del = -del;
        }

        if (!ok) continue;
        res += del * (n / mul);
    }

    cout << res;

    return 0;
}
