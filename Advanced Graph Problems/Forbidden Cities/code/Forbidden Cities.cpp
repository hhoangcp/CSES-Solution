
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> V[100006];
int low[100006], num[100006], lab[100006], P[100006][18];
int out[100006], n, m, q;

void DFS(int u) {
    low[u] = 1e9, num[u] = ++num[0];

    P[u][0] = lab[u];
    for(int i=1; i<=17; ++i) P[u][i] = P[P[u][i-1]][i-1];

    for(int v: V[u])
    if (lab[u] != v) {
        if (num[v]) low[u] = min(low[u], num[v]);
        else {
            lab[v] = u;
            DFS(v);
            low[u] = min(low[u], low[v]);
        }
    }

    out[u] = num[0];
}

bool in(int u, int v) {
    return num[u] <= num[v] && out[v] <= out[u];
}

int find_parent(int p, int v) {
    for(int i=17; i>=0; --i) {
        int u = P[v][i];
        if (u > 0 && u != p && in(p, u)) v = u;
    }

    return v;
}

bool Checking(int A, int B, int C, int D) {
    if (num[C] > num[D]) swap(C, D);
    return P[D][0] != C || low[D] <= num[C] || in(D, A) == in(D, B);
}

bool Checking(int A, int B, int C) {
    if (num[A] > num[B]) swap(A, B);

    if (C == A || C == B) return false;
    if (P[B][0] == A) return true;

    if (in(A, B)) {
        if (in(A, C) && in(C, B)) {
            B = find_parent(C, B);
            if (low[B] < num[C]) return true;
            return false;
        }
    }

    if (in(A, C) || in(B, C)) return true;

    if (in(C, A) && in(C, B)) {
        A = find_parent(C, A);
        B = find_parent(C, B);

        if (A == B) return true;
        if (low[A] < num[C] && low[B] < num[C]) return true;
        return false;
    }

    if (in(C, A)) {
        A = find_parent(C, A);
        if (low[A] < num[C]) return true;
        return false;
    }

    if (in(C, B)) {
        B = find_parent(C, B);
        if (low[B] < num[C]) return true;
        return false;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> m >> q;
    for(int i=1; i<=m; ++i) {
        int u, v; cin >> u >> v;

        V[u].push_back(v);
        V[v].push_back(u);
    }

    for(int u=1; u<=n; ++u)
    if (!num[u]) DFS(u);

    while (q--) {
        int A, B, C; cin >> A >> B >> C;
        if (Checking(A, B, C)) cout << "YES\n"; else cout << "NO\n";
    }

    return 0;
}
