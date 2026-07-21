
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#define llong long long

using namespace std;

struct Data {
    int len, link;
    map<char, int> Next;
    llong dp = 0;
} SA[200006];

int n, q, sz = 0, last;
char S[100006];

void Init() {
    SA[0].len = 0; SA[0].link = -1;
    ++sz; last = 0;
}

void Build_Suffix_Automation(char c) {
    int cur = sz++, p;
    SA[cur].len = SA[last].len + 1;
    for(p = last; p != -1 && !SA[p].Next.count(c); p = SA[p].link) SA[p].Next[c] = cur;

    if (p == -1) SA[cur].link = 0;
    else {
        int q = SA[p].Next[c];

        if (SA[p].len + 1 == SA[q].len) SA[cur].link = q;
        else {
            int clone = sz++;
            SA[clone].len = SA[p].len + 1;
            SA[clone].link = SA[q].link;
            SA[clone].Next = SA[q].Next;

            for(; p != -1 && SA[p].Next[c] == q; p = SA[p].link) SA[p].Next[c] = clone;

            SA[cur].link = SA[q].link = clone;
        }
    }

    last = cur;
}

int Num[200006], Topo[200006];

void Topo_Sort() {
    for(int i = 0; i < sz; ++i) Num[i] = 0;
    for(int i = 0; i < sz; ++i) ++Num[SA[i].len];
    for(int i = sz - 2; i >= 0; --i) Num[i] += Num[i+1];
    for(int i = sz - 1; i >= 0; --i) Topo[--Num[SA[i].len]] = i;
}

const llong MAX = 2e18;
llong Add(llong A, llong B) {
    return min(MAX, A + B);
}

void DP_path() {
    for(int i = 0; i < sz; ++i) {
        int u = Topo[i];

        for(map<char, int>::iterator it = SA[u].Next.begin(); it != SA[u].Next.end(); ++it)
            SA[u].dp = Add(SA[u].dp, SA[it->second].dp + 1);
    }
}

char ans[100006];

void Find_string(llong k) {
    int len = 0, cur = 0;
    if (SA[0].dp < k) {
        puts("No solution");
        return;
    }

    while (k > 0) {
        for(map<char, int>::iterator it = SA[cur].Next.begin(); it != SA[cur].Next.end(); ++it) {
            char c = it->first; int Next = it->second;

            if (SA[Next].dp + 1 < k) k -= SA[Next].dp + 1;
            else {
                --k;
                ans[len++] = c;
                cur = Next;
                break;
            }
        }
    }

    ans[len] = '\0';
    puts(ans);
}

int main() {
    scanf("%s", S); n = strlen(S); Init();
    for(int i = 0; i < n; ++i) Build_Suffix_Automation(S[i]);

    Topo_Sort();
    DP_path();

    llong k; scanf("%lld", &k);
    Find_string(k);

    return 0;
}
