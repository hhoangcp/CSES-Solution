
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
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

char S[200006];

int main() {
    scanf("%s", S); int n = strlen(S);

    int h = 1;
    while (h <= n) h <<= 1;
    h <<= 1;

    vector<Complex> A(h, {0.0, 0.0}), B(h, {0.0, 0.0}), C(h);

    for(int i = 0; i < n; ++i)
    if (S[i] == '1') {
        A[i].a += 1.0;
        B[n-1-i].a += 1.0;
    }

    FFT(A, false), FFT(B, false);
    for(int i = 0; i < h; ++i) C[i] = A[i] * B[i];
    FFT(C, true);

    for(int i = 1; i < n; ++i) cout << (int) round(C[n-1+i].a) << ' ';

    return 0;
}
