
#include <iostream>
#include <algorithm>
#include <queue>
#define llong long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int n; cin >> n;
    llong ans = 0;
    priority_queue<int> Q;

    for(int i = 1; i <= n; ++i) {
        int a; cin >> a;
        Q.push(a);
        ans += Q.top() - a;
        Q.pop(); Q.push(a);
    }

    cout << ans;

    return 0;
}
