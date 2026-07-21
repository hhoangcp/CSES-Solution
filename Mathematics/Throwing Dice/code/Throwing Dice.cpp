
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

const llong mod = 1e9 + 7;

struct matrix {
    llong a[6][6];

    matrix() {
        for(int i = 0; i < 6; ++i)
        for(int j = 0; j < 6; ++j) a[i][j] = 0;
    }
};

matrix operator * (const matrix &A, const matrix &B) {
    matrix C = matrix();

    for(int i=0; i<6; ++i)
    for(int j=0; j<6; ++j)
    for(int k=0; k<6; ++k) C.a[i][j] = (C.a[i][j] + A.a[i][k] * B.a[k][j] % mod) % mod;

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

    if (n <= 1) {
        cout << 1;
        return 0;
    }

    matrix A = matrix();
    for(int i = 0; i < 5; ++i)
        A.a[i][i+1] = A.a[5][i] = 1;

    A.a[5][5] = 1;
    cout << power(A, n).a[5][5];

    return 0;
}
