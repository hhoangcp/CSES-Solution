
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct Data {
    int grid, dist;
};

int power[10];

int Swap(int grid, int i, int j) {
    int x = grid % power[i+1] / power[i];
    int y = grid % power[j+1] / power[j];

    return grid + (x - y) * (power[j] - power[i]);
}

int base = 6053444;
bool visited[375313601];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    power[0] = 1; int s = 0;
    for(int i = 1; i <= 9; ++i) {
        int x; cin >> x; --x;

        s += x * power[i-1];
        power[i] = power[i-1] * 9;
    }

    queue<Data> Q; Q.push({s, 0}); visited[s - base] = true;
    while (!Q.empty()) {
        Data u = Q.front(); Q.pop();

        if (u.grid == 381367044) {
            cout << u.dist;
            return 0;
        }

        int grid = u.grid, dist = u.dist;
        for(int i = 0; i < 8; ++i) {
            if (i % 3 < 2) {
                int new_grid = Swap(grid, i, i+1);
                if (!visited[new_grid - base]) {
                    visited[new_grid - base] = true;
                    Q.push({new_grid, dist + 1});
                }
            }

            if (i < 6) {
                int new_grid = Swap(grid, i, i+3);
                if (!visited[new_grid - base]) {
                    visited[new_grid - base] = true;
                    Q.push({new_grid, dist + 1});
                }
            }
        }
    }

    cout << "?????";

    return 0;
}
