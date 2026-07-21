
#include <iostream>
#include <algorithm>
#include <map>
#define llong long long

using namespace std;

map<int, int> M;
int n;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n; M.insert({0, 1});
    llong res = 0; int prefix = 0;
    for(int i = 1; i <= n; ++i) {
        int a; cin >> a; prefix = ((prefix + a) % n + n) % n;

        if (M.count(prefix)) res += M[prefix]++;
        else M.insert({prefix, 1});
    }

    cout << res;

    return 0;
}
