
#include <cstdio>
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        llong X1, Y1, X2, Y2, X3, Y3;
        cin >> X1 >> Y1 >> X2 >> Y2 >> X3 >> Y3;

        if ((X2 - X1) * (Y3 - Y1) - (X3 - X1) * (Y2 - Y1) < 0) puts("RIGHT");
        else if ((X2 - X1) * (Y3 - Y1) - (X3 - X1) * (Y2 - Y1) > 0) puts("LEFT");
        else puts("TOUCH");
    }

    return 0;
}
