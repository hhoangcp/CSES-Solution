
#include <iostream>
#include <algorithm>

using namespace std;

const int mod = 1e9+7;

int main() {
    int n; cin >> n;

    int power = 1;
    for(int i=1; i<=n; ++i) power = power * 2 % mod;
    cout << power;

    return 0;
}
