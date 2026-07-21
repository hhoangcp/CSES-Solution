
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

char S[1000006], tmp[1000006];
int n, ans;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n; ans = 1e9;
    for(int len = 0; (len << 1) <= n; ++len) {
        int a = len, b = n - len;

        int cur = 0;
        while (min(a, b) >= 0 && max(a, b) > 0) {
            if (a >= b) {
                tmp[++cur] = '0';
                a -= (b + 1);
            } else {
                tmp[++cur] = '1';
                b -= (a + 1);
            }
        }

        if (a == 0 && b == 0 && ans > cur) {
            ans = cur;
            for(int i = 1; i <= cur; ++i) S[i] = tmp[i];
            S[cur+1] = 0;
        }
    }

    cout << S+1;

    return 0;
}
