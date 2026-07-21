#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

int a[1006][1006], n, q;
char S[1006];

int main() {
    ///freopen("inp.txt", "r", stdin);
    scanf("%d%d", &n, &q);
    ///
    for(int i=1; i<=n; ++i) {
        scanf("%s", S+1);
        for(int j=1; j<=n; ++j) a[i][j] = a[i-1][j] + a[i][j-1] - a[i-1][j-1] + (S[j] == '*');
    }
    ///
    for(int i=1; i<=q; ++i) {
        int x, y, u, v; scanf("%d%d%d%d", &x, &y, &u, &v);
        ///
        cout << a[u][v] - a[u][y-1] - a[x-1][v] + a[x-1][y-1] << "\n";
    }
    return 0;
}
