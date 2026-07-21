
#include <iostream>
#include <algorithm>
#include <queue>
#define llong long long

using namespace std;

struct TEdge {
    int v, c;
} Edges[400006];

priority_queue<llong> Best[100006];
priority_queue<pair<llong, int>, vector<pair<llong, int> >, greater<pair<llong, int> > > PQ;
int n, m, k, link[400006], head[100006];
int heap[100006], pos[100006], n_heap = 0;

void dijkstra() {
    Best[1].push(0);
    PQ.push({0, 1});

    while (!PQ.empty()) {
        pair<llong, int> u = PQ.top(); PQ.pop();
        if (u.first > Best[u.second].top()) continue;

        int i = head[u.second];

        while (i > 0) {
            int v = Edges[i].v, c = Edges[i].c;
            llong tmp = u.first + c;

            if ((int) Best[v].size() < k) {
                Best[v].push(tmp);
                PQ.push({tmp, v});
            } else if (tmp < Best[v].top()) {
                Best[v].pop();
                Best[v].push(tmp);
                PQ.push({tmp, v});
            }

            i = link[i];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> m >> k;
    for(int i=1; i<=m; ++i) {
        int u, v, c; cin >> u >> v >> c;

        Edges[i] = {v, c};
        link[i] = head[u]; head[u] = i;
    }

    dijkstra();
    vector<llong> ans;

    while (!Best[n].empty()) {
        ans.push_back(Best[n].top());
        Best[n].pop();
    }

    while (!ans.empty()) {
        cout << ans.back() << ' ';
        ans.pop_back();
    }

    return 0;
}
