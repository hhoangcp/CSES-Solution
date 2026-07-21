
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

queue<int> Q;
int Next[2000006], n, len[200006], steps = 0;
bool visited[200006];

void DFS(int u) {
    Q.push(u);

    if (visited[u]) {
        steps += len[u];
        return;
    }

    visited[u] = true;
    ++steps;
    DFS(Next[u]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> Next[i];

    for(int u = 1; u <= n; ++u)
    if (!visited[u]) {
        steps = 0;
        DFS(u);
        int sub = 1;

        while (!Q.empty()) {
            if (Q.front() == Q.back()) sub = 0;

            len[Q.front()] = steps;
            steps -= sub;
            Q.pop();
        }
    }

    for(int u = 1; u <= n; ++u) cout << len[u] << ' ';

    return 0;
}
