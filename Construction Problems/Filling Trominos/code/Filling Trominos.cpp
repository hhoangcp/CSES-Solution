
#include <iostream>
#include <algorithm>

using namespace std;

char ans[106][106];
bool Rotate;

char Get_char(int x, int y) {
    (x -= 1) %= 5, (y -= 1) %= 5;
    return char('A' + x * 5 + y);
}

void Set_2x3(int x, int y) {
    char C1 = Get_char(x, y), C2 = Get_char(x+1, y+2);

    ans[x][y] = ans[x+1][y] = ans[x][y+1] = C1;
    ans[x+1][y+2] = ans[x+1][y+1] = ans[x][y+2] = C2;
}

void Set_3x2(int x, int y) {
    char C1 = Get_char(x, y), C2 = Get_char(x+2, y+1);

    ans[x][y] = ans[x+1][y] = ans[x][y+1] = C1;
    ans[x+2][y+1] = ans[x+1][y+1] = ans[x+2][y] = C2;
}

void Set_5x9(int x, int y) {
    Set_3x2(x, y); Set_3x2(x+2, y+5); Set_3x2(x+2, y+7);
    Set_2x3(x+3, y); Set_2x3(x, y+6);

    char cur;

    cur = Get_char(x, y+2);
    ans[x][y+2] = ans[x][y+3] = ans[x+1][y+2] = cur;

    cur = Get_char(x+2, y+2);
    ans[x+2][y+2] = ans[x+2][y+3] = ans[x+3][y+3] = cur;

    cur = Get_char(x+1, y+3);
    ans[x+1][y+3] = ans[x+1][y+4] = ans[x+2][y+4] = cur;

    cur = Get_char(x, y+4);
    ans[x][y+4] = ans[x][y+5] = ans[x+1][y+5] = cur;

    cur = Get_char(x+3, y+4);
    ans[x+3][y+4] = ans[x+4][y+3] = ans[x+4][y+4] = cur;
}

void Set_nx9(int n) {
    Set_5x9(1, 1);

    for(int i = 6; i < n; i += 2) {
        Set_2x3(i, 1);
        Set_2x3(i, 4);
        Set_2x3(i, 7);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t = 0; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;

        Rotate = false;
        if (m % 3) {
            Rotate = true;
            swap(n, m);
        }

        if (m % 3) {
            cout << "NO\n";
            continue;
        }

        if ((m == 3 && n % 2) || (n == 3 && m % 2)) {
            cout << "NO\n";
            continue;
        }

        if (n == 1) {
            cout << "NO\n";
            continue;
        }

        if (n % 2) {
            if (m % 2) {
                Set_nx9(n);

                for(int i = 10; i < m; i += 2) Set_3x2(1, i);

                for(int i = 4; i < n; i += 2)
                for(int j = 10; j < m; j += 3) Set_2x3(i, j);
            } else {
                for(int i = 1; i < m; i += 2) Set_3x2(1, i);

                for(int i = 4; i < n; i += 2)
                for(int j = 1; j < m; j += 3) Set_2x3(i, j);
            }
        } else {
            for(int i = 1; i < n; i += 2)
            for(int j = 1; j < m; j += 3) Set_2x3(i, j);
        }

        cout << "YES\n";
        if (Rotate) {
            for(int i = 1; i <= m; ++i) {
                for(int j = 1; j <= n; ++j) cout << ans[j][i];
                cout << '\n';
            }
        } else {
            for(int i = 1; i <= n; ++i) {
                for(int j = 1; j <= m; ++j) cout << ans[i][j];
                cout << '\n';
            }
        }
    }

    return 0;
}
