
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int dist[1000006], n;
bool visited[1000006];

int main() {
    cin >> n;
    queue<int> Q; Q.push(n); visited[n] = true, dist[n] = 0;

    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        if (u == 0) break;

        int tmp = u;
        while (tmp > 0) {
            int v = u - tmp % 10;

            if (!visited[v]) {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                Q.push(v);
            }

            tmp /= 10;
        }
    }

    cout << dist[0];

    return 0;
}
