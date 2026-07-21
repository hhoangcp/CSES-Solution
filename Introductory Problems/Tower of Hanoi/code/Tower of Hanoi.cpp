
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

void TowerOfHaNoi(int n, int from, int to, int mid) {
    /// Move disk n

    if (n == 1) {
        cout << from << ' ' << to << '\n';
        return;
    }

    TowerOfHaNoi(n-1, from, mid, to);
    cout << from << ' ' << to << '\n';
    TowerOfHaNoi(n-1, mid, to, from);
}

int main() {
    int n; cin >> n;

    cout << (1 << n) - 1 << '\n';
    TowerOfHaNoi(n, 1, 3, 2);

    return 0;
}
