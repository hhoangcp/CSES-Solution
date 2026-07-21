
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

int t, n;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> t;
    while (t--) {
        int n; cin >> n;

        int Xor = 0;
        while (n--) {
            int a; cin >> a; a %= 4;
            Xor ^= a;
        }

        if (Xor != 0) cout << "first\n"; else cout << "second\n";
    }

    return 0;
}
