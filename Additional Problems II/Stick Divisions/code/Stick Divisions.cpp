
#include <iostream>
#include <algorithm>
#include <queue>
#define llong long long

using namespace std;

llong ans = 0, x;
int n;

int main() {
    ios_base::sync_with_stdio(NULL); cin.tie(NULL);

    priority_queue<llong, vector<llong>, greater<llong> > PQ;

    cin >> x >> n;
    for(int i = 1; i <= n; ++i) {
        int a; cin >> a;
        PQ.push(a);
    }

    while ((int) PQ.size() > 1) {
        llong a = PQ.top(); PQ.pop();
        llong b = PQ.top(); PQ.pop();

        ans += a + b;
        PQ.push(a + b);
    }

    cout << ans;

    return 0;
}
