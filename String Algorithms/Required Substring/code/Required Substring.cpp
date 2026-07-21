
#include <iostream>
#include <algorithm>
#include <string>
#define llong long long

using namespace std;

const int mod = 1e9+7;

llong dp[1006][106];
int n, m, Z[206], longest[106][26];
string S;

void Z_function(string A, string B) {
    A = A + '.' + B;

    int len = A.size(); Z[0] = 0;
    for(int i = 1, L = 0, R = 0; i < len; ++i) {
        if (i <= R) Z[i] = min(Z[i-L], R-i+1); else Z[i] = 0;
        while (i + Z[i] < len && A[Z[i]] == A[i+Z[i]]) ++Z[i];
        if (i + Z[i] - 1 > R) {
            R = i + Z[i] - 1;
            L = i;
        }
    }
}

int main() {
    cin >> n >> S; m = S.size();

    for(int i = 0; i < m; ++i)
    for(int c = 0; c < 26; ++c) {
        string T = S.substr(0, i);
        T = T + char(c + 'A');

        Z_function(S, T);
        for(int j = m + 1; j < (int) m + i + 2; ++j)
            if (Z[j] + j - 1 == (int) m + i + 1) {
                longest[i][c] = Z[j];
                break;
            }
    }

    /// dp[i][j] la so xau do dai i khong chua S va co hau to do dai j trung voi tien to cua S
    dp[0][0] = 1;
    for(int i = 1; i <= n; ++i)
    for(int j = 0; j < m; ++j)
    for(int c = 0; c < 26; ++c)
        (dp[i][longest[j][c]] += dp[i-1][j]) %= mod;

    llong ans = 1;
    for(int i = 0; i < n; ++i) (ans *= 26) %= mod;
    for(int i = 0; i < m; ++i) ans = (ans - dp[n][i] + mod) % mod;

    cout << ans;

    return 0;
}
