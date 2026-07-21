
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

char S[1006][1006];
int m, n;
bool visited[1006][1006];

void BFS(int sx, int sy) {
    queue<pair<int, int> > Q; Q.push({sx, sy}); visited[sx][sy] = true;

    while (!Q.empty()) {
        pair<int, int> u = Q.front(); Q.pop();

        for(int i = 0; i < 4; ++i) {
            pair<int, int> v = {u.first + dx[i], u.second + dy[i]};

            if (v.first < 1 || v.first > m || v.second < 1 || v.second > n || visited[v.first][v.second] || S[v.first][v.second] == '#') continue;

            visited[v.first][v.second] = true;
            Q.push(v);
        }
    }
}

int main() {
    scanf("%d%d", &m, &n);
    for(int i = 1; i <= m; ++i) scanf("%s", S[i] + 1);

    int num = 0;
    for(int i = 1; i <= m; ++i)
    for(int j = 1; j <= n; ++j)
    if (!visited[i][j] && S[i][j] == '.') {
        ++num;
        BFS(i, j);
    }

    cout << num;

    return 0;
}
