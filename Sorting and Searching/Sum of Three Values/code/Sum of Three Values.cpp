
#include <iostream>
#include <algorithm>

using namespace std;

struct Data {
    int a, p;

    bool operator < (const Data &other) const {
        return a < other.a;
    }
} A[5006];

int n, x;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> x;
    for(int i = 1; i <= n; ++i) {
        cin >> A[i].a;
        A[i].p = i;
    }

    sort(A+1, A+n+1);

    for(int l = 1; l <= n; ++l) {
        int mid = l + 1, r = n, X = x - A[l].a;

        do {
            while (mid < r && A[mid].a + A[r].a > X) --r;
            if (mid >= r) break;

            if (A[mid].a + A[r].a == X) {
                cout << A[l].p << ' ' << A[mid].p << ' ' << A[r].p;
                return 0;
            }

            ++mid;
        } while (mid < r);
    }

    cout << "IMPOSSIBLE";

    return 0;
}
