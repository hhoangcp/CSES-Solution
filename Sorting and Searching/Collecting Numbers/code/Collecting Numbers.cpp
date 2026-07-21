
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int n, pos[200006];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;
    for(int i=1; i<=n; ++i) {
        int a; cin >> a;
        pos[a] = i;
    }

    int Round = 1;
    for(int i=2; i<=n; ++i)
    if (pos[i] < pos[i-1]) ++Round;

    cout << Round;

    return 0;
}
