
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#define llong long long
#define PI 3.14159265358979323846

using namespace std;

struct Complex {
    double x, y;

    Complex operator /= (const int &n) {x /= n, y /= n; return (*this);}
    Complex operator * (const Complex &other) {return {x *other.x - y * other.y, x * other.y + y * other.x};}
    Complex operator + (const Complex &other) {return {x + other.x, y + other.y};}
    Complex operator - (const Complex &other) {return {x - other.x, y - other.y};}
};

char S[200006];
int n;

void FFT(vector<Complex> &A, bool invert) {
    int sz = A.size();

    for(int i = 1, j = 0; i < sz; ++i) {
        int bit = sz >> 1;

        for(; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;

        if (i < j) swap(A[i], A[j]);
    }

    for(int len = 2; len <= sz; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1: 1);

        Complex wlen = {cos(ang), sin(ang)};
        for(int i = 0; i < sz; i += len) {
            Complex w = {1.0, 0.0};

            for(int j = 0; j < (len >> 1); ++j) {
                Complex u = A[i+j], v = A[i+j+(len>>1)] * w;

                A[i+j] = u+v;
                A[i+j+(len>>1)] = u-v;

                w = w * wlen;
            }
        }
    }

    if (invert) for(int i = 0; i < sz; ++i) A[i] /= sz;
}

int main() {
    scanf("%s", S+1); n = strlen(S+1);

    vector<int> Num;

    int num = 0; llong zero = 0;
    for(int i = 1; i <= n; ++i)
    if (S[i] == '0') ++num;
    else {
        zero += 1LL * num * (num + 1) / 2;
        Num.push_back(num + 1);
        num = 0;
    }

    Num.push_back(num + 1);
    zero += 1LL * num * (num + 1) / 2;
    cout << zero << ' ';

    int N = Num.size(), h = 1;

    while (h < N) h <<= 1;
    h <<= 1;

    vector<Complex> A(h, {0.0, 0.0}), B(h, {0.0, 0.0});
    for(int i = 0; i < N; ++i) {
        A[i].x = Num[i];
        if (i > 0) B[N-i-1].x = Num[i];
    }

    FFT(A, false), FFT(B, false);
    for(int i = 0; i < h; ++i) A[i] = A[i] * B[i];
    FFT(A, true);

    for(int i = N-2; i>=0; --i) cout << (llong) round(A[i].x) << ' ';
    for(int i = N; i <= n; ++i) cout << 0 << ' ';

    return 0;
}
