
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define PI 3.14159265358979323846

using namespace std;

struct Complex {
    double a, b; /// a + bi

    Complex operator /= (const int &k) {a /= k, b /= k; return (*this);}
    Complex operator * (const Complex &other) {return {a * other.a - b*other.b, a*other.b + b*other.a};}
    Complex operator + (const Complex &other) {return {a + other.a, b + other.b};}
    Complex operator - (const Complex &other) {return {a - other.a, b - other.b};}
};

void FFT(vector<Complex> &A, bool invert) {
    int n = A.size();

    for(int i = 1, j = 0; i < n; ++i) {
        int bit = n >> 1;
        for(; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;

        if (i < j) swap(A[i], A[j]);
    }

    for(int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);

        Complex wlen = {cos(ang), sin(ang)};
        for(int i = 0; i < n; i += len) {
            Complex w = {1.0, 0.0};

            for(int j = 0; j < len / 2; ++j) {
                Complex u = A[i+j], v = A[i+j+len/2] * w;

                A[i+j] = u + v;
                A[i+j+len/2] = u - v;

                w = w * wlen;
            }
        }
    }

    if (invert)
        for(int i = 0; i < n; ++i) A[i] /= n;
}

int k, m, n;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> k >> m >> n;

    int h = 1;
    while (h <= k) h <<= 1;
    h <<= 1;

    vector<Complex> A(h, {0.0, 0.0}), B(h, {0.0, 0.0}), C(h);

    for(int i = 1; i <= m; ++i) {
        int a; cin >> a;
        A[a].a += 1.0;
    }

    for(int i = 1; i <= n; ++i) {
        int b; cin >> b;
        B[b].a += 1.0;
    }

    FFT(A, false), FFT(B, false);
    for(int i = 0; i < h; ++i) C[i] = A[i] * B[i];
    FFT(C, true);

    for(int i = 2; i <= 2 * k; ++i) cout << (long long) round(C[i].a) << ' ';

    return 0;
}
