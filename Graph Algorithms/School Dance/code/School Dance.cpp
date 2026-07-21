
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> V[506];
int n, m, k, match[506];
bool visited[506];

bool DFS(int u) {
    for(int v: V[u])
    if (!visited[v]) {
        visited[v] = true;

        if (match[v] == 0 || DFS(match[v])) {
            match[v] = u;
            return true;
        }
    }

    return false;
}

void Max_matching() {
    vector<int> tmp;
    for(int i = n; i >= 1; --i) tmp.push_back(i);

    bool stop = false;
    int max_matching = 0;

    while (!stop) {
        stop = true;

        for(int v = 1; v <= m; ++v) visited[v] = false;

        for(int i = tmp.size() - 1; i >= 0; --i) {
            int u = tmp[i];

            if (DFS(u)) {
                ++max_matching;
                stop = false;
                tmp[i] = tmp.back();
                tmp.pop_back();
            }
        }
    }

    cout << max_matching << '\n';
    for(int i = 1; i <= m; ++i)
    if (match[i] != 0) cout << match[i] << ' ' << i << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> m >> k;
    for(int i = 1; i <= k; ++i) {
        int u, v; cin >> u >> v;
        V[u].push_back(v);
    }

    Max_matching();

    return 0;
}
