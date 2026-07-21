
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

llong sum[400006], k;
int n, a[400006], Binary_lifting[400006][21];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> k;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i]; a[i+n] = a[i];
        sum[i] = sum[i-1] + a[i];
    }

    n <<= 1;
    for(int i = (n >> 1) + 1; i <= n; ++i) sum[i] = a[i] + sum[i-1];

    for(int i = 1; i <= n; ++i)
        Binary_lifting[i][0] = upper_bound(sum + i, sum + n + 1, sum[i-1] + k) - sum;

    for(int i = 1; i <= 19; ++i)
    for(int j = 1; j <= n; ++j)
        Binary_lifting[j][i] = Binary_lifting[Binary_lifting[j][i-1]][i-1];

    int ans = (n >> 1);
    for(int i = 1; (i << 1) <= n; ++i) {
        int cur = i;
        int div = 1;

        for(int j = 19; j >= 0; --j)
        if (Binary_lifting[cur][j] != 0 && Binary_lifting[cur][j] < (n >> 1) + i) {
            div += (1 << j);
            cur = Binary_lifting[cur][j];
        }

        ans = min(ans, div);
    }

    cout << ans;

    return 0;
}
