
#include <iostream>
#include <algorithm>
#include <stack>
#include <cstring>

using namespace std;

stack<int> V[27];
int n, start = 0, Next[1000006];
char S[1000006];

int main() {
    scanf("%s", S+1); n = strlen(S+1);

    for(int i = n; i >= 1; --i)
    if (S[i] == '#') {
        V[0].push(i);
        start = i;
    } else V[S[i] - 'a' + 1].push(i);

    for(int i = 1, cur = 0; i <= n; ++i) {
        while (V[cur].empty()) ++cur;
        Next[i] = V[cur].top(); V[cur].pop();
    }

    for(int cur = Next[start]; cur != start; cur = Next[cur]) putchar(S[cur]);

    return 0;
}
