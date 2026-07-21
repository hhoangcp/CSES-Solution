
#include <iostream>
#include <algorithm>

using namespace std;

int n, num[1000006];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; ++i) {
        int a; cin >> a;
        ++num[a];
    }

    for(int i = 1000000; i >= 1; --i) {
        int cnt = 0;

        for(int j = i; j <= 1000000; j += i) {
            cnt += num[j];

            if (cnt >= 2) {
                cout << i;
                return 0;
            }
        }
    }

    return 0;
}
