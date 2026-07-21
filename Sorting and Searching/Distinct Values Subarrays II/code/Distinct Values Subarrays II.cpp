
#include <iostream>
#include <algorithm>
#include <map>
#define llong long long

using namespace std;

map<int, int> M;
int n, k, a[200006], diff = 0;

void Add(int x) {
    if (!M.count(x)) {
        M.insert({x, 1});
        ++diff;
    } else ++M[x];
}

void Sub(int x) {
    --M[x];
    if (M[x] == 0) {
        --diff;
        M.erase(x);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> k;
    llong res = 0;

    for(int i = 1, l = 1; i <= n; ++i) {
        cin >> a[i]; Add(a[i]);

        while (l < i && diff > k) Sub(a[l++]);
        res += (i - l + 1);
    }

    cout << res;

    return 0;
}
