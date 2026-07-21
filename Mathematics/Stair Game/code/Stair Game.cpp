
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
        for(int i = 1; i <= n; ++i) {
            int a; cin >> a;
            if ((i & 1) == 0) Xor ^= a;
        }

        if (Xor != 0) cout << "first\n"; else cout << "second\n";
    }

    return 0;
}
