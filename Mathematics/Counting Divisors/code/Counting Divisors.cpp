
#include <iostream>
#include <algorithm>

using namespace std;

int n, DIV[1000006];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    for(int i = 1; i <= 1000000; ++i)
    for(int j = i; j <= 1000000; j += i) ++DIV[j];

    cin >> n;
    while (n--) {
        int x; cin >> x;
        cout << DIV[x] << '\n';
    }

    return 0;
}
