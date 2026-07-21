
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

int a[200006], bit[200006], n;
bool visited[200006];

void Method_1() {
    llong ans = 0;
    fill(bit, bit+n+1, 0);
    for(int i = 1; i <= n; ++i) {
        for(int p = n - a[i]; p > 0; p -= (p & (-p))) ans += bit[p];
        for(int p = n - a[i] + 1; p <= n; p += (p & (-p))) ++bit[p];
    }

    cout << ans << ' ';
}

void Method_2() {
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        if (visited[i]) continue;

        int len = 0;
        for(int u = i; !visited[u]; u = a[u]) {
            ++len;
            visited[u] = true;
        }

        ans += len - 1;
    }

    cout << ans << ' ';
}

void Method_3() {
    int ans = n - 1;
    fill(bit, bit+n+1, 0);
    for(int i = 1; i <= n; ++i) {
        int best = 0;
        for(int p = a[i] - 1; p > 0; p -= (p & (-p))) best = max(best, bit[p]);

        ans = min(ans, n - ++best);
        for(int p = a[i]; p <= n; p += (p & (-p))) bit[p] = max(bit[p], best);
    }

    cout << ans << ' ';
}

void Method_4() {
    int ans = n;
    for(int i = n; i >= 1; --i)
    if (a[i] == ans) --ans;

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];

    Method_1();
    Method_2();
    Method_3();
    Method_4();

    return 0;
}
