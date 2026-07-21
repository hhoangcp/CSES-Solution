
#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

struct Data {
    map<char, int> Next;
    int len, link, first_pos;
} SA[200006];

int n, q, last, sz = 0;
char S[100006], T[500006];

void Init() {
    SA[0].len = SA[0].first_pos = 0; SA[0].link = -1;
    ++sz; last = 0;
}

void Build_Suffix_Automaton(char c) {
    int cur = sz++, p;
    SA[cur].len = SA[last].len + 1; SA[cur].first_pos = SA[cur].len;

    for(p = last; p != -1 && !SA[p].Next.count(c); p = SA[p].link) SA[p].Next.insert({c, cur});

    if (p == -1) SA[cur].link = 0;
    else {
        int q = SA[p].Next[c];

        if (SA[q].len == SA[p].len + 1) SA[cur].link = q;
        else {
            int clone = sz++;

            SA[clone].len = SA[p].len + 1;
            SA[clone].link = SA[q].link;
            SA[clone].Next = SA[q].Next;
            SA[clone].first_pos = SA[q].first_pos;

            for(; p != -1 && SA[p].Next.count(c) && SA[p].Next[c] == q; p = SA[p].link)
                SA[p].Next[c] = clone;

            SA[q].link = SA[cur].link = clone;
        }
    }

    last = cur;
}

int main() {
    scanf("%s", S+1); n = strlen(S+1); Init();
    for(int i = 1; i <= n; ++i) Build_Suffix_Automaton(S[i]);

    scanf("%d", &q);
    while (q--) {
        scanf("%s", T+1); int m = strlen(T+1);

        int cur = 0;
        bool ok = true;

        for(int i = 1; i <= m; ++i) {
            if (!SA[cur].Next.count(T[i])) {
                ok = false;
                break;
            }

            cur = SA[cur].Next[T[i]];
        }

        if (ok) cout << SA[cur].first_pos - m + 1 << '\n';
        else cout << -1 << '\n';
    }

    return 0;
}
