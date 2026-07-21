
#include <iostream>
#include <algorithm>

using namespace std;

const int mod = 1e9+7;
int bit[200006];
int n, N, sorted[200006], a[200006];

void Update(int p, int val) {
    for(; p <= N; p += (p & (-p))) (bit[p] += val) %= mod;
}

int Query(int p) {
    int sum = 0;
    for(; p > 0; p -= (p & (-p))) (sum += bit[p]) %= mod;
    return sum;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        sorted[i] = a[i];
    }

    sort(sorted+1, sorted+n+1);
    N = unique(sorted+1, sorted+n+1) - sorted - 1;

    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        a[i] = lower_bound(sorted+1, sorted+N+1, a[i]) - sorted;

        int sum = (Query(a[i] - 1) + 1) % mod;
        (ans += sum) %= mod;

        Update(a[i], sum);
    }

    cout << ans;

    return 0;
}
