
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<pair<int, int> > > Rounds;
int n, a[200006];
bool visited[200006];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];

    Rounds.push_back(vector<pair<int, int> >(0, {0, 0}));
    for(int i = 1; i <= n; ++i) {
        if (visited[i]) continue;

        vector<int> S;
        for(int u = i; !visited[u]; u = a[u]) {
            visited[u] = true;
            S.push_back(u);
        }

        for(int l = 0, r = S.size() - 1; l < r; ++l, --r) {
            swap(a[S[l]], a[S[r]]);
            Rounds[Rounds.size() - 1].push_back({S[l], S[r]});
        }
    }

    if (!Rounds.back().empty()) Rounds.push_back(vector<pair<int, int> >(0, {0, 0}));
    for(int i = 1; i <= n; ++i)
    if (a[i] < i) Rounds[Rounds.size() - 1].push_back({a[i], i});

    while (!Rounds.empty() && Rounds.back().empty()) Rounds.pop_back();

    cout << Rounds.size() << '\n';
    for(vector<pair<int, int> > round: Rounds) {
        cout << round.size() << '\n';
        for(pair<int, int> p: round) cout << p.first << ' ' << p.second << '\n';
    }

    return 0;
}
