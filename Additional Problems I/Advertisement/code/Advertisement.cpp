
#include <iostream>
#include <algorithm>
#include <vector>
#define llong long long

using namespace std;

int n, h[200006], L[200006];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;

    vector<int> S; S.clear();
    for(int i = 1; i <= n; ++i) {
        cin >> h[i];

        while (!S.empty() && h[S.back()] >= h[i]) S.pop_back();
        if (S.empty()) L[i] = 0; else L[i] = S.back();

        S.push_back(i);
    }

    llong res = 0; S.clear();
    for(int i = n; i >= 1; --i) {
         while (!S.empty() && h[S.back()] >= h[i]) S.pop_back();
         int R; if (S.empty()) R = n+1; else R = S.back();

         res = max(res, 1LL * h[i] * (R - L[i] - 1));
         S.push_back(i);
    }

    cout << res;

    return 0;
}
