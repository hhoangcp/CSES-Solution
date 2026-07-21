#include <algorithm>
#include <iostream>
#include <vector>
#include <cassert>
#define ll long long
#define ull unsigned long long

using namespace std;

pair<int, int> sum[10000006];
bool avail[10000006];

void init() {
    for (int i = 0; i * i <= 10'000'000; ++i)
        for (int j = 0; j * j <= 10'000'000 && i * i + j * j <= 10'000'000; ++j) {
            int total = i * i + j * j;
            sum[total] = make_pair(i, j);
            avail[total] = true;
        }
}

void solve() {
    int n; cin >> n;

    for (int i = 0; i <= n; ++i)
        if (avail[i] && avail[n - i]) {
            cout << sum[i].first << " " << sum[i].second << " ";
            cout << sum[n - i].first << " " << sum[n - i].second << "\n";
            break;
        }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    init();

    int tests = 1; cin >> tests;
    for (int i = 0; i < tests; ++i) {
        solve();
    }
}
