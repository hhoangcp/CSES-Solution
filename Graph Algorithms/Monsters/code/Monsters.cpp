/// Monster

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

struct Data {
    int type;
    int x, y;
} A, trace[1006][1006];

int m, n, cnt = 0;
char S[1006], res[1000006];
bool visited[1006][1006];
queue<Data> Q;

bool check(const Data &p) {
    return 1 <= p.x && p.x <= m && 1 <= p.y && p.y <= n && !visited[p.x][p.y];
}

bool borderline(const Data &p) {
    if (!check(p)) return false;
    return p.x == 1 || p.x == m || p.y == 1 || p.y == n;
}

char vec(const Data &p, const Data &s) {
    char ret;

    if (p.x == s.x) {
        if (p.y < s.y) ret = 'R';
        else ret = 'L';
    } else {
        if (p.x < s.x) ret = 'D';
        else ret = 'U';
    }

    return ret;
}

void BFS() {
    int cnt_A = 1;

    do {
        Data u = Q.front(); Q.pop();
        if (u.type == 1) --cnt_A;

        for(int i=0; i<4; ++i) {
            Data v = {u.type, u.x + dx[i], u.y + dy[i]} ;

            if (u.type == 1 && borderline(v)) {
                trace[v.x][v.y] = u;

                puts("YES");

                while (v.x != A.x || v.y != A.y) {
                    Data pre = trace[v.x][v.y];
                    res[++cnt] = vec(pre, v);
                    v = pre;
                }

                cout << cnt << "\n";
                for(int i=cnt; i>=1; --i) putchar(res[i]);
                exit(0);
            } else if (check(v)) {
                visited[v.x][v.y] = u.type;
                if (u.type == 1) trace[v.x][v.y] = u, ++cnt_A;
                Q.push(v);
            }
        }
    } while (!Q.empty() && cnt_A > 0);

    cout << "NO";
}

int main() {
    ///freopen("inp.txt", "r", stdin);

    scanf("%d%d", &m, &n);
    for(int i=1; i<=m; ++i) {
        scanf("%s", S+1);

        for(int j=1; j<=n; ++j)
        if (S[j] != '.') {
            if (S[j] == 'M') Q.push({2, i, j});
            else if (S[j] == 'A') {
                if (borderline({1, i, j})) {
                    puts("YES");
                    putchar('0');
                    return 0;
                }

                A = {1, i, j};
            }

            visited[i][j] = true;
        }
    }

    Q.push(A);
    BFS();

    return 0;
}
