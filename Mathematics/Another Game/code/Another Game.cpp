
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        bool ok = false;
        for(int i = 1; i <= n; ++i) {
            int a; cin >> a;
            if (a & 1) ok = true;
        }

        if (ok) cout << "first\n"; else cout << "second\n";
    }

    return 0;
}
