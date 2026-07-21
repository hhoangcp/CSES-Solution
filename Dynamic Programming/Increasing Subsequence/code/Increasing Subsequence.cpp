
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> LIS;
int n;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;
    for(int i=1; i<=n; ++i) {
        int a; cin >> a;

        vector<int>::iterator p = lower_bound(LIS.begin(), LIS.end(), a);
        if (p == LIS.end()) LIS.push_back(a);
        else (*p) = a;
    }

    cout << LIS.size();

    return 0;
}
