
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

map<int, pair<int, int> > M;
int n, x, a[1006];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> x;
    for(int i = 1; i <= n; ++i) cin >> a[i];

    M.insert({a[1] + a[2], make_pair(1, 2)});
    for(int i = 3; i < n; ++i) {
        for(int j = i + 1; j <= n; ++j) {
            int X = x - a[i] - a[j];

            if (M.count(X)) {
                cout << M[X].first << ' ' << M[X].second << ' ' << i << ' ' << j;
                return 0;
            }
        }

        for(int j = 1; j < i; ++j) M.insert({a[i] + a[j], make_pair(j, i)});
    }

    cout << "IMPOSSIBLE";

    return 0;
}
