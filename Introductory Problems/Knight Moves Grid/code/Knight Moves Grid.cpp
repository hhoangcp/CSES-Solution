#include <iostream>
#include <queue>

using namespace std;

const int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
const int dy[8] = {1, -1, 1, -1, 2, -2, 2, -2};

struct Point {
    int x, y;
};

int grid[1006][1006];
bool visited[1006][1006];

void BFS(int n) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            visited[i][j] = false, grid[i][j] = 0;

    visited[0][0] = true;
    queue<Point> q; q.push({0, 0});

    while (!q.empty()) {
        Point u = q.front(); q.pop();

        for (int i = 0; i < 8; i++) {
            Point v = {u.x + dx[i], u.y + dy[i]};

            if (v.x < 0 || v.x >= n || v.y < 0 || v.y >= n || visited[v.x][v.y]) continue;
            visited[v.x][v.y] = true;
            grid[v.x][v.y] = grid[u.x][u.y] + 1;
            q.push(v);
        }
    }
}

void solve() {
    int n; cin >> n;

    BFS(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << grid[i][j] << " ";
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int tests = 1; //cin >> tests;
    for (int i = 0; i < tests; ++i) {
        solve();
    }
}