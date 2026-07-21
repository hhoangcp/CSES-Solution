#include <iostream>

using namespace std;

int grid[128][128];

void solve() {
    grid[0][0] = grid[1][1] = 0, grid[1][0] = grid[0][1] = 1;

    for (int len = 4; len <= 128; len <<= 1) {
        int mid = len >> 1;

        for (int i = mid; i < len; ++i)
            for (int j = mid; j < len; ++j) grid[i][j] = grid[i - mid][j - mid];

        for (int i = 0; i < mid; ++i)
            for (int j = 0; j < mid; ++j) grid[i][j + mid] = grid[i + mid][j] = grid[i][j] + mid;
    }

    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) cout << grid[i][j] << " ";
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int tests = 1; //cin >> tests;
    for (int i = 0; i < tests; ++i) {
        solve();
    }
}