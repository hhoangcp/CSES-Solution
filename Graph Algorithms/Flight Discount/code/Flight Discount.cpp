#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

struct TEdge {
    int v, c;
} Edges[400006];

struct Data {
    int u, k;
} heap[200006];

int n, m, s, t, link[400006], head[100006];
int pos[100006][2], n_heap = 0;
llong d[100006][2];

void update_heap(int u, int k) {
    if (pos[u][k] == 0) heap[++n_heap] = {u, k}, pos[u][k] = n_heap;

    int child = pos[u][k], parent = child / 2;
    while (parent > 0) {
        if (d[heap[parent].u][heap[parent].k] <= d[heap[child].u][heap[child].k]) break;

        swap(pos[heap[parent].u][heap[parent].k], pos[heap[child].u][heap[child].k]);
        swap(heap[parent], heap[child]);
        child = parent, parent = child / 2;
    }
}

Data top_pop_heap() {
    Data top = heap[1]; pos[top.u][top.k] = 0;
    heap[1] = heap[n_heap--];
    if (n_heap == 0) return top;

    pos[heap[1].u][heap[1].k] = 1;

    int parent = 1, child = parent * 2;
    while (child <= n_heap) {
        if (child < n_heap && d[heap[child].u][heap[child].k] > d[heap[child+1].u][heap[child+1].k]) ++child;
        if (d[heap[parent].u][heap[parent].k] <= d[heap[child].u][heap[child].k]) break;

        swap(pos[heap[parent].u][heap[parent].k], pos[heap[child].u][heap[child].k]);
        swap(heap[parent], heap[child]);
        parent = child, child = parent * 2;
    }

    return top;
}

void dijkstra() {
    for(int i=1; i<=n; ++i) d[i][0] = d[i][1] = 1e18;
    d[1][0] = 0;
    update_heap(1, 0);

    do {
        Data u = top_pop_heap();
        int i = head[u.u];

        while (i > 0) {
            int v = Edges[i].v, c = Edges[i].c;

            if (d[v][u.k] > d[u.u][u.k] + c) {
                d[v][u.k] = d[u.u][u.k] + c;
                update_heap(v, u.k);
            }

            if (u.k == 0 && d[v][u.k+1] > d[u.u][u.k] + c / 2) {
                d[v][u.k+1] = d[u.u][u.k] + c / 2;
                update_heap(v, u.k+1);
            }

            i = link[i];
        }
    } while (n_heap > 0);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> m;
    for(int i=1; i<=m; ++i) {
        int u, v, c; cin >> u >> v >> c;

        Edges[i] = {v, c};
        link[i] = head[u]; head[u] = i;
    }

    dijkstra();
    cout << min(d[n][0], d[n][1]);

    return 0;
}
