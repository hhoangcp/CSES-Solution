
#include <cstdio>
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

pair<int, int> P[200006];
int n;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; ++i) cin >> P[i].first >> P[i].second;

    sort(P, P+n);

    llong res = 0, cur = 0;
    for(int i = 0; i < n; ++i) {
        cur += P[i].first;
        res += P[i].second - cur;
    }

    cout << res;

    return 0;
}
