
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

ordered_set S;
int n, k;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> k;
    for(int i=1; i<=n; ++i) S.insert(i);


    int cur = k % n;
    while (n--) {
        ordered_set::iterator it = S.find_by_order(cur);
        cout << *it << ' ';
        S.erase(it);
        if (n > 0) cur = (cur % n + k) % n;
    }

    return 0;
}
