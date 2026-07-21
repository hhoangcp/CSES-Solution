 
#include <iostream>
#include <algorithm>
#define file_name "1625"
 
using namespace std;
 
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};
 
char S[56];
bool avail[9][9];
 
bool check(int x, int y) {
    return 1 <= x && x <= 7 && 1 <= y && y <= 7 && !avail[x][y];
}
 
int res = 0;
 
void Try(int p, int x, int y) {
    if (x == 1 && y == 7) res += (p == 49);
    else {
        if (((y == 7 || (avail[x][y+1] && avail[x][y-1])) && x + 1 <= 7 && x - 1 > 0 && !avail[x+1][y] && !avail[x-1][y])
            || ((x == 7 || (avail[x+1][y] && avail[x-1][y])) && y + 1 <= 7 && y - 1 > 0 && !avail[x][y+1] && !avail[x][y-1])
            || ((y == 1 || (avail[x][y+1] && avail[x][y-1])) && x + 1 <= 7 && x - 1 > 0 && !avail[x+1][y] && !avail[x-1][y])
            || ((x == 1 || (avail[x+1][y] && avail[x-1][y])) && y + 1 <= 7 && y - 1 > 0 && !avail[x][y+1] && !avail[x][y-1])) return;
 
 
        avail[x][y] = true;
 
        if (S[p] == '?') {
            for(int i=0; i<4; ++i) {
                int u = dx[i] + x;
                int v = dy[i] + y;
 
                if (check(u, v)) {
                    Try(p+1, u, v);
                }
            }
        } else {
            switch(S[p]) {
                case 'R': {
                    if (check(x+1, y)) Try(p+1, x+1, y);
                    break;
                }
 
                case 'L': {
                    if (check(x-1, y)) Try(p+1, x-1, y);
                    break;
                }
 
                case 'U': {
                    if (check(x, y-1)) Try(p+1, x, y-1);
                    break;
                }
 
                case 'D': {
                    if (check(x, y+1)) Try(p+1, x, y+1);
                    break;
                }
            }
        }
 
        avail[x][y] = false;
    }
}
 
int main() {
    ///freopen(file_name".INP", "r", stdin);
    ///freopen(file_name".OUT", "w", stdout);
 
    scanf("%s", S+1);
 
    Try(1, 1, 1);
    cout << res;
    return 0;
}