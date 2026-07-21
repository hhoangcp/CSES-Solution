
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int n, a[200006];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    stack<int> S;
    while (!S.empty()) S.pop();

    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];

        while (!S.empty() && a[S.top()] >= a[i]) S.pop();
        if (S.empty()) cout << 0 << ' '; else cout << S.top() << ' ';
        S.push(i);
    }

    return 0;
}
