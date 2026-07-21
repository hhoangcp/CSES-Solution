#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#define ll long long
#define ull unsigned long long

using namespace std;

int manacher[400005];

void solve() {
    string s; cin >> s;

    int n = s.length();
    string t = "$";
    for (int i = 0; i < n; ++i) t.push_back(s[i]), t.push_back('$');

    int len = 2 * n + 1;
    for (int i = 0, l = -1, r = -1; i < len; ++i) {
        manacher[i] = (i <= r) ? min(r - i, manacher[2 * l - i]) : 0;
        while (i + manacher[i] + 1 < len && i - manacher[i] - 1 >= 0 && t[i - manacher[i] - 1] == t[i + manacher[i] + 1]) ++manacher[i];
        if (i + manacher[i] > r) {
            l = i;
            r = i + manacher[i];
        }
    }

    queue<int> q;
    for (int i = 0; i < len; ++i) {
        while (!q.empty() && i - q.front() + 1 > manacher[q.front()]) q.pop();
        q.push(i);
        if (i % 2 == 1) cout << i - q.front() + 1 << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tests = 1; //cin >> tests;
    for (int i = 0; i < tests; ++i) {
        solve();
    }
}
