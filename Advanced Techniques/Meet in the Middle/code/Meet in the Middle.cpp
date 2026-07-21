
#include <iostream>
#include <algorithm>
#include <vector>
#define llong long long

using namespace std;

vector<int> D1, D2;
int n, x, a[46];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> x;
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    int mid = n / 2;

    for(int i = 0; i < (1 << mid); ++i) {
        int sum = 0;
        bool ok = true;

        for(int j = 0; j < mid; ++j)
        if (i & (1 << j)) {
            sum += a[j];
            if (sum > x) {
                ok = false;
                break;
            }
        }

        if (ok) D1.push_back(sum);
    }

    for(int i = 0; i < (1 << (n - mid)); ++i) {
        int sum = 0;
        bool ok = true;

        for(int j = 0; j < n - mid; ++j)
        if (i & (1 << j)) {
            sum += a[j + mid];
            if (sum > x) {
                ok = false;
                break;
            }
        }

        if (ok) D2.push_back(sum);
    }

    sort(D1.begin(), D1.end());
    sort(D2.begin(), D2.end());

    llong res = 0;

    int l = D2.size(), r = D2.size();
    for(int val: D1) {
        while (l > 0 && D2[l-1] >= x - val) --l;
        while (r > 0 && D2[r-1] > x - val) --r;

        res += r - l;
    }

    cout << res;

    return 0;
}
