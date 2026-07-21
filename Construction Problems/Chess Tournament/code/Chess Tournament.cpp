
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

vector<pair<int, int> > Ans, tmp;
priority_queue<pair<int, int> > Q;
int n;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; ++i) {
        int a; cin >> a;
        Q.push({a, i});
    }

    for(int i = 1; i <= n; ++i) {
        tmp.clear();
        pair<int, int> u = Q.top(); Q.pop();

        while (u.first > 0 && !Q.empty()) {
            pair<int, int> v = Q.top(); Q.pop();

            if (v.first == 0) return cout << "IMPOSSIBLE", 0;

            Ans.push_back({u.second, v.second});
            --v.first; --u.first; tmp.push_back(v);
        }

        if (u.first > 0) return cout << "IMPOSSIBLE", 0;
        for(pair<int, int> v: tmp) Q.push(v);
    }

    cout << Ans.size() << '\n';
    for(pair<int, int> u: Ans) cout << u.first << ' ' << u.second << '\n';

    return 0;
}
