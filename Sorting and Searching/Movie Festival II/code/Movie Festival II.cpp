
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

struct Data {
    int l, r;

    bool operator < (const Data &other) const {
        return r < other.r;
    }
} P[200006];

multiset<int> Ends;
int n, k;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> k;
    for(int i = 0; i < n; ++i) cin >> P[i].l >> P[i].r;

    sort(P, P+n);
    for(int i = 0; i < k; ++i) Ends.insert(0);

    int res = 0;
    for(int i = 0; i < n; ++i) {
        auto it = Ends.upper_bound(P[i].l);
        if (it == begin(Ends)) continue;

        Ends.erase(--it);
        Ends.insert(P[i].r);

        ++res;
    }

    cout << res;

    return 0;
}
