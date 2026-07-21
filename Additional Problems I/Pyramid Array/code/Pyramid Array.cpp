
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

int bit[200006], n;
int inv[200006], a[200006], sorted[200006];

void Add(int p) {
    for(; p <= n; p += (p & (-p))) ++bit[p];
}

int Query(int p) {
    int sum = 0;
    for(; p > 0; p -= (p & (-p))) sum += bit[p];
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

    for(int i = 1; i <= n; ++i) {
        a[i] = lower_bound(sorted+1, sorted+n+1, a[i]) - sorted;
        inv[i] = i - 1 - Query(a[i]);
        Add(a[i]);
    }

    fill(bit+1, bit+n+1, 0);

    llong ans = 0;
    for(int i = n; i >= 1; --i) {
        ans += min(inv[i], n - i - Query(a[i]));
        Add(a[i]);
    }

    cout << ans;

    return 0;
}
