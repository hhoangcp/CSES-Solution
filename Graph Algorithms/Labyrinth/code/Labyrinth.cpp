
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

struct Point {
    int x, y;

    bool operator == (const Point &other) const {
        return x == other.x && y == other.y;
    }
} s, t, trace[1006][1006];

int m, n, depth[1006][1006];
char S[1006][1006];
bool visited[1006][1006];

void BFS() {
    queue<Point> Q; Q.push(s); visited[s.x][s.y] = true;

    while (!Q.empty()) {
        Point u = Q.front(); Q.pop();
        if (u == t) return;

        for(int i = 0; i < 4; ++i) {
            Point v = {u.x + dx[i], u.y + dy[i]};

            if (v.x < 1 || v.x > m || v.y < 1 || v.y > n || visited[v.x][v.y] || S[v.x][v.y] == '#') continue;

            visited[v.x][v.y] = true;
            trace[v.x][v.y] = u;
            depth[v.x][v.y] = depth[u.x][u.y] + 1;
            Q.push(v);
        }
    }
}

int main() {
    scanf("%d%d", &m, &n);
    for(int i = 1; i <= m; ++i) {
        scanf("%s", S[i] + 1);

        for(int j = 1; j <= n; ++j) {
            if (S[i][j] == 'B') s = {i, j};
            if (S[i][j] == 'A') t = {i, j};
        }
    }

    BFS();

    if (!visited[t.x][t.y]) cout << "NO";
    else {
        puts("YES");
        cout << depth[t.x][t.y] << '\n';

        while (!(t == s)) {
            Point p = trace[t.x][t.y];

            if (t.y > p.y) putchar('L');
            if (t.y < p.y) putchar('R');
            if (t.x > p.x) putchar('U');
            if (t.x < p.x) putchar('D');

            t = p;
        }
    }

    return 0;
}
