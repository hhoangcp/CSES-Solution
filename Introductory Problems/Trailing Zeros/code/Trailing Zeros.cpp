
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

int main() {
    int n; cin >> n;

    llong res = 0;
    while (n > 0) {
        n /= 5;
        res += n;
    }

    cout << res;
    return 0;
}
