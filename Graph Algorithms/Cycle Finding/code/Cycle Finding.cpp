
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define llong long long

using namespace std;

struct Data {
    int v, c;
};

vector<Data> V[2506];
llong dist[2506];
int n, m, trace[2506], cnt[2506];
bool in_queue[2506];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int u, v, c; cin >> u >> v >> c;
        V[u].push_back({v, c});

        if (u == v && c < 0) {
            cout << "YES\n" << u << ' ' << v;
            return 0;
        }
    }

    queue<int> Q;
    for(int i = 1; i <= n; ++i) {
        dist[i] = 0;
        cnt[i] = 0;
        in_queue[i] = true;
        Q.push(i);
    }

    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        in_queue[u] = false;

        for(Data v : V[u]) {
            if (dist[v.v] > dist[u] + v.c) {
                dist[v.v] = dist[u] + v.c;
                trace[v.v] = u;

                if (++cnt[v.v] >= n) {
                    int x = v.v;
                    for(int i = 0; i < n; ++i) x = trace[x];

                    vector<int> cycle;
                    cycle.push_back(x);
                    for(int y = trace[x]; y != x; y = trace[y])
                        cycle.push_back(y);
                    reverse(cycle.begin(), cycle.end());

                    cout << "YES\n";
                    for(int node : cycle) cout << node << ' ';
                    cout << cycle[0];

                    return 0;
                }

                if (!in_queue[v.v]) {
                    in_queue[v.v] = true;
                    Q.push(v.v);
                }
            }
        }
    }

    cout << "NO";

    return 0;
}
