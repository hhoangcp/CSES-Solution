
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#define llong long long

using namespace std;

typedef vector<vector<llong> > Matrix;

Matrix operator * (const Matrix &A, const Matrix &B) {
    Matrix C; C.assign(A.size(), vector<llong>(A.size(), (llong) 3e18));

    for(int i=1; i<(int) C.size(); ++i)
    for(int j=1; j<(int) C.size(); ++j)
    for(int k=1; k<(int) C.size(); ++k) C[i][j] = min(C[i][j],  A[i][k] + B[k][j]);

    return C;
}

Matrix Power(Matrix A, llong k) {
    if (k == 1) return A;

    Matrix tmp = Power(A, k >> 1);
    tmp = tmp * tmp;

    if (k & 1) tmp = tmp * A;
    return tmp;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int n, m; llong k; cin >> n >> m >> k;

    Matrix A; A.assign(n+1, vector<llong> (n+1, (llong) 3e18));
    while (m--) {
        int u, v, C; cin >> u >> v >> C;
        A[u][v] = min(A[u][v], 1LL * C);
    }

    Matrix res = Power(A, k);
    if (res[1][n] == 3e18) cout << -1;
    else cout << res[1][n];

    return 0;
}
