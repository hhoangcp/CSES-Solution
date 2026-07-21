
#include <iostream>

using namespace std;

int n;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n; --n;

    int Xor = 0;
    for(int i = 0; i <= n; ++i) {
        int a; cin >> a;
        if ((i & n) == i) Xor ^= a;
    }

    cout << Xor;

    return 0;
}
