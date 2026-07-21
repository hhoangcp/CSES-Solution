#include <algorithm>
#include <iostream>

using namespace std;

int a[100006], b[100006], c[100006], freq[100006];

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i]--;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        b[i]--;
    }

    if (n <= 2) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    fill(freq, freq + n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        freq[(b[i] - a[i] + n) % n]++;
    }

    int shift = 1;
    while (shift < n && freq[shift] != 0) shift++;

    if (shift < n) {
        for (int i = 1; i <= n; ++i) {
            c[i] = (a[i] + shift) % n + 1;
        }
    } else {
        int p1 = 1;
        while ((b[p1] - a[p1] + n) % n != n / 2) p1++;
        int p2 = p1 + 1;
        while ((b[p2] - a[p2] + n) % n != n / 2) p2++;

        for (int i = 1; i <= n; ++i) {
            c[i] = (a[i] + n / 2) % n + 1;
        }

        if ((a[p2] - a[p1] + n) % n != n / 2) {
            c[p1] = (a[p2] + n / 2) % n + 1;
            c[p2] = (a[p1] + n / 2) % n + 1;
        } else {
            int p3 = 1;
            while (p3 == p1 || p3 == p2) p3++;
            int p4 = p3 + 1;
            while (p4 == p1 || p4 == p2) p4++;

            c[p1] = (a[p3] + n / 2) % n + 1;
            c[p2] = (a[p4] + n / 2) % n + 1;
            c[p3] = (a[p1] + n / 2) % n + 1;
            c[p4] = (a[p2] + n / 2) % n + 1;
        }
    }

    for (int i = 1; i <= n; ++i) cout << c[i] << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tests = 1; 
    for (int i = 0; i < tests; ++i) {
        solve();
    }
}