
#include <iostream>
#include <algorithm>

using namespace std;

char S[9][9];
bool column[9], ld[18], rd[18];
int res;

void Try(int p) {
    if (p > 8) { ++res; return; }

    for(int i=1; i<=8; ++i)
    if (!column[i] && !ld[p - i + 8] && !rd[p + i] && S[p][i] == '.') {
        column[i] = ld[p - i + 8] = rd[p + i] = true;
        Try(p+1);
        column[i] = ld[p - i + 8] = rd[p + i] = false;
    }
}

int main() {
    ///freopen("1624.inp", "r", stdin);

    for(int i=1; i<=8; ++i) scanf("%s", S[i]+1);

    Try(1);
    cout << res;

    return 0;
}
