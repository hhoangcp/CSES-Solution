
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

llong k;
int n;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> k;
    for(int l = 1, r = n; l <= r;) {
        if (r - l <= k) {
            cout << r << ' ';
            k -= r-- - l;
        } else cout << l++ << ' ';
    }

    return 0;
}
