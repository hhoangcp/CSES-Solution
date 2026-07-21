
#include <iostream>
#include <algorithm>

using namespace std;

int q;

int Get_ans(int n, int k) {
    if (n == 1) return 1;

    if (k <= (n + 1) / 2) {
        if (2 * k > n) return (2 * k) % n;
        return 2 * k;
    }

    int p = Get_ans(n >> 1, k - (n + 1) / 2);
    if (n & 1) return 2 * p + 1;
    return 2 * p - 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> q;
    while (q--) {
        int n, k; cin >> n >> k;
        cout << Get_ans(n, k) << '\n';
    }

    return 0;
}
