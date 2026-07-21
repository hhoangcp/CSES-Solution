#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

struct TEdge {
    int v, c;
} Edges[400006];

int n, m, s, t, link[400006], head[100006];
int heap[100006], pos[100006], n_heap = 0;
llong d[100006];

void update_heap(int u) {
    if (pos[u] == 0) heap[++n_heap] = u, pos[u] = n_heap;

    int child = pos[u], parent = child / 2;
    while (parent > 0) {
        if (d[heap[parent]] <= d[heap[child]]) break;
        swap(pos[heap[parent]], pos[heap[child]]);

        swap(heap[parent], heap[child]);
        child = parent, parent = child / 2;
    }
}

int top_pop_heap() {
    int top = heap[1]; pos[top] = 0;
    heap[1] = heap[n_heap--];
    if (n_heap == 0) return top;

    pos[heap[1]] = 1;

    int parent = 1, child = parent * 2;
    while (child <= n_heap) {
        if (child < n_heap && d[heap[child]] > d[heap[child+1]]) ++child;
        if (d[heap[parent]] <= d[heap[child]]) break;

        swap(pos[heap[parent]], pos[heap[child]]);
        swap(heap[parent], heap[child]);
        parent = child, child = parent * 2;
    }
    return top;
}

void dijkstra() {
    for(int i=1; i<=n; ++i) d[i] = 1e18;
    d[1] = 0;
    update_heap(1);

    do {
        int u = top_pop_heap();
        int i = head[u];

        while (i > 0) {
            int v = Edges[i].v, c = Edges[i].c;
            if (d[v] > d[u] + c) {
                d[v] = d[u] + c;
                update_heap(v);
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
    for(int i = 1; i <= n; ++i) cout << d[i] << ' ';

    return 0;
}
