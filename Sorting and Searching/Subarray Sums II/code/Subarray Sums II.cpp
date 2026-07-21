
#include <iostream>
#include <algorithm>
#include <map>
#define llong long long

using namespace std;

map<llong, int> M;
int n, x;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> x; M.insert({0, 1});
    llong prefix = 0, res = 0;
    for(int i = 1; i <= n; ++i) {
        int a; cin >> a; prefix += a;

        if (M.count(prefix - x)) res += M[prefix - x];

        if (M.count(prefix)) ++M[prefix]; else M.insert({prefix, 1});
    }

    cout << res;

    return 0;
}
