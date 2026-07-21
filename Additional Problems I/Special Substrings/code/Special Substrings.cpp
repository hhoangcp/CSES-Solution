
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
#define llong long long

using namespace std;

map<vector<int>, int> M;
int n, cnt[26], pos[26], idx = 0;
char S[200006];
bool tick[26];

int main() {
    scanf("%s", S+1); n = strlen(S+1);

    vector<int> cur(0, 0);
    for(int i = 1; i <= n; ++i) {
        int c = S[i] - 'a';
        if (!tick[c]) {
            tick[c] = true;
            cur.push_back(0);
            pos[c] = idx++;
        }
    }

    cur.pop_back();
    M.insert({cur, 1});

    llong ans = 0;
    for(int i = 1; i <= n; ++i) {
        int c = S[i] - 'a';
        ++cnt[pos[c]];

        for(int i = 1; i < idx; ++i)
            cur[i-1] = cnt[i] - cnt[i-1];

        if (M.count(cur)) ans += M[cur]++;
        else M.insert({cur, 1});
    }

    cout << ans;

    return 0;
}
