
#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>
#include <vector>

using namespace std;

struct Data {
    map<char, int> nxt;
    int len, link;
    vector<int> inv_link;
} SA[200006];

int n, q, last, sz = 0;
char S[100006], T[500006];

void Init() {
    SA[0].len = 0, SA[0].link = -1;
    ++sz;
    last = 0;
}

int cnt[200006];

void Build_Suffix_Automaton(char c) {
    int cur = sz++, p;
    SA[cur].len = SA[last].len + 1; cnt[cur] = 1;
    for(p = last; p != -1 && !SA[p].nxt.count(c); p = SA[p].link) SA[p].nxt.insert({c, cur});

    if (p == -1) SA[cur].link = 0;
    else {
        int q = SA[p].nxt[c];

        if (SA[q].len == SA[p].len + 1) SA[cur].link = q;
        else {
            int clone = sz++;

            SA[clone].len = SA[p].len + 1;
            SA[clone].link = SA[q].link;
            SA[clone].nxt = SA[q].nxt;

            for(; p != -1 && SA[p].nxt.count(c) && SA[p].nxt[c] == q; p = SA[p].link) SA[p].nxt[c] = clone;
            SA[q].link = SA[cur].link = clone;
        }
    }

    last = cur;
}

void DFS(int cur) {
    for(int up: SA[cur].inv_link) {
        DFS(up);
        cnt[cur] += cnt[up];
    }
}

int main() {
    scanf("%s", S+1); n = strlen(S+1); Init();
    for(int i = 1; i <= n; ++i) Build_Suffix_Automaton(S[i]);

    for(int i = 1; i < sz; ++i) SA[SA[i].link].inv_link.push_back(i);
    DFS(0);

    scanf("%d", &q);
    while (q--) {
        scanf("%s", T+1); int m = strlen(T+1);

        int cur = 0;
        bool ok = true;

        for(int i = 1; i <= m; ++i) {
            if (!SA[cur].nxt.count(T[i])) {
                ok = false;
                break;
            }

            cur = SA[cur].nxt[T[i]];
        }

        if (ok) cout << cnt[cur] << '\n';
        else puts("0");
    }

    return 0;
}
