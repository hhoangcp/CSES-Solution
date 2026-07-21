
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#define llong long long

using namespace std;

const int mod = 1e9+7;
typedef vector<vector<llong> > Matrix;
Matrix Zero;

Matrix operator * (const Matrix &A, const Matrix &B) {
    Matrix C; C.assign(A.size(), vector<llong>(A.size(), 0LL));

    for(int i=1; i<(int) C.size(); ++i)
    for(int j=1; j<(int) C.size(); ++j)
    for(int k=1; k<(int) C.size(); ++k) C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;

    return C;
}

Matrix Power(Matrix A, llong k) {
    Matrix res = Zero;

    while (k > 0) {
        if (k & 1) res = res * A;
        A = A * A;
        k >>= 1;
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int n, m; llong k; cin >> n >> m >> k;

    Zero.assign(n+1, vector<llong> (n+1, 0LL));
    Matrix A; A.assign(n+1, vector<llong> (n+1, 0LL));
    for(int i=1; i<=n; ++i) Zero[i][i] = 1;

    while (m--) {
        int u, v; cin >> u >> v;
        ++A[u][v];
    }

    Matrix res = Power(A, k);
    cout << res[1][n];

    return 0;
}
