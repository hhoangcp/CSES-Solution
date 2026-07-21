
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

int dx[8] = {2, 1, 1, 2, -1, -2, -2, -1};
int dy[8] = {1, 2, -2, -1, 2, 1, -1, -2};

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int a[9][9];

bool limit(int x, int y) {
    return min(x, y) >= 1 && max(x, y) <= 8;
}

bool isEmpty(int x, int y) {
    return limit(x, y) && a[x][y] < 0;
}

int get_degree(int x, int y) {
    int cnt = 0;
    for(int i = 0; i < 8; ++i)
    if (isEmpty(x + dx[i], y + dy[i])) ++cnt;

    return cnt;
}

bool Next_move(int &x, int &y) {
    int idx = -1, min_deg = 16, c, u, v;

    int start = rng() % 8;
    for(int j = 0; j < 8; ++j) {
        int i = (start + j) % 8;

        u = x + dx[i];
        v = y + dy[i];

        if (isEmpty(u, v) && (c = get_degree(u, v)) < min_deg) {
            min_deg = c;
            idx = i;
        }
    }

    if (idx == -1) return false;

    u = x + dx[idx];
    v = y + dy[idx];

    a[u][v] = a[x][y] + 1;
    x = u, y = v;

    return true;
}

bool neighbour(int x, int y, int u, int v) {
    for(int i = 0; i < 8; ++i)
    if ((u + dx[i] == x) && (v + dy[i] == y)) return true;

    return false;
}

bool Find_tour(int x, int y) {
    for(int i = 1; i <= 8; ++i)
    for(int j = 1; j <= 8; ++j) a[i][j] = -1;

    a[x][y] = 1;
    int u = x, v = y;

    for(int i = 1; i < 64; ++i)
        if (!Next_move(u, v)) return false;

    /// if (!neighbour(x, y, u, v)) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int x, y; cin >> y >> x;
    while (!Find_tour(x, y));

    for(int i = 1; i <= 8; ++i) {
        for(int j = 1; j <= 8; ++j) cout << a[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}
