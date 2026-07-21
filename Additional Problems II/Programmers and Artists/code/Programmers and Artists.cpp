/// Greedy

#include <iostream>
#include <algorithm>
#include <queue>
#define llong long long

using namespace std;

struct Data {
    int a, b;

    bool operator > (const Data &other) const {
        return a - b > other.a - other.b;
    }
} D[200006];

priority_queue<int, vector<int>, greater<int> > PQ;
llong dp[200006];
int n, A, B;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> A >> B >> n;
    for(int i = 1; i <= n; ++i) {
        int a, b; cin >> a >> b;
        D[i] = {a, b};
    }

    sort(D+1, D+n+1, greater<Data>());

    llong sum = 0;
    for(int i = 1; i <= n; ++i) {
        sum += D[i].a; PQ.push(D[i].a);

        if ((int) PQ.size() > A) {
            sum -= PQ.top();
            PQ.pop();
        }

        if (i >= A) dp[i] = sum;
    }

    if (A == n || B == 0) {
        cout << dp[n];
        return 0;
    }

    sum = 0;
    while (!PQ.empty()) PQ.pop();

    llong ans = 0;
    for(int i = n; i > A; --i) {
        sum += D[i].b; PQ.push(D[i].b);

        if ((int) PQ.size() > B) {
            sum -= PQ.top();
            PQ.pop();
        }

        if (i <= n-B+1) ans = max(ans, sum + dp[i-1]);
    }

    cout << ans;

    return 0;
}
