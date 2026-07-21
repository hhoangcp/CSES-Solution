
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

const llong mod = 1e9 + 7;

struct matrix {
    llong a[2][2];

    matrix() {
        a[0][0] = a[0][1] = a[1][0] = a[1][1] = 0;
    }
};

matrix operator * (const matrix &A, const matrix &B) {
    matrix C = matrix();

    for(int i=0; i<2; ++i)
    for(int j=0; j<2; ++j)
    for(int k=0; k<2; ++k) C.a[i][j] = (C.a[i][j] + A.a[i][k] * B.a[k][j] % mod) % mod;

    return C;
}

matrix power(matrix A, llong N) {
    if (N == 1) return A;

    matrix tmp = power(A, N>>1);
    tmp = tmp * tmp;

    if (N & 1) tmp = tmp * A;
    return tmp;
}

llong n;

int main() {
    cin >> n;

    if (n == 0) {
    	cout << 0;
    	return 0;
    }
    --n;

    if (n <= 1) {
        cout << 1;
        return 0;
    }

    matrix A = matrix();
    A.a[0][1] = A.a[1][0] = A.a[1][1] = 1;

    cout << power(A, n).a[1][1];
    return 0;
}
