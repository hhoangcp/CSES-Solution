
#include <iostream>
#include <algorithm>

using namespace std;

int a[106], b[5006], n, m, pos[106];

bool Finding_answer(int p) {
    for(int i = 2; i <= n; ++i) pos[i] = i+1;

    a[2] = (b[p] - b[2] + b[1]) >> 1;
    a[3] = a[2] - b[1] + b[2];
    a[1] = b[1] - a[2];

    for(int i = 3; i < p; ++i) a[i+1] = b[i] - a[1];
    pos[2] = 4;

    int cur = p;

    for(int i = p+1; i <= m; ++i) {
        bool ok = false;

        for(int j = 2; j <= cur && !ok; ++j) {
            if (pos[j] > cur) continue;
            if (a[j] + a[pos[j]] == b[i]) {
                ok = true;
                ++pos[j];
            }
        }

        if (!ok && cur >= n) return false;
        if (!ok) a[++cur] = b[i] - a[1];
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n; m = n * (n - 1) / 2;
    for(int i = 1; i <= m; ++i) cin >> b[i];

    sort(b+1, b+m+1);

    for(int i = 3; i <= n; ++i)
    if (!((b[i] - b[2] + b[1]) & 1))
    if (Finding_answer(i)) {
        for(int j = 1; j <= n; ++j) cout << a[j] << ' ';
        return 0;
    }

    cout << -1;

    return 0;
}
