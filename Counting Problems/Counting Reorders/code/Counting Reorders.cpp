#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define uint128 __uint128_t
#define int128 __int128
#define float128 __float128
#define ld long double
#define ll long long
#define ull unsigned ll
#define llong ll
#define ullong ull
#define ldouble long double
#define uint unsigned int
#define sint short int
#define eb emplace_back
#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define fst first
#define snd second
#define pii pair<int, int>
#define pil pair<ll, int>
#define pli pair<int, ll>
#define pll pair<ll, ll>
#define tiii tuple<int, int, int>
#define pld pair<ld, ld>
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define getbit(x, i) (((x) >> (i)) & 1)
#define cntbit(x) __builtin_popcount(x)
#define FOR(i,l,r) for (int i = l; i <= r; i++)
#define FORD(i,l,r) for (int i = l; i >= r; i--)

using namespace std;
using namespace __gnu_pbds;

const int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
const int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};

template<unsigned mod_>
struct mint {
    static constexpr unsigned mod = mod_;
    unsigned x;
    constexpr mint() : x(0U) {}
    constexpr mint(unsigned x_) : x(x_ % mod) {}
    constexpr mint(ullong x_) : x(x_ % mod) {}
    constexpr mint(int x_) : x(((x_ %= static_cast<int>(mod)) < 0) ? (x_ + static_cast<int>(mod)) : x_) {}
    constexpr mint(llong x_) : x(((x_ %= static_cast<llong>(mod)) < 0) ? (x_ + static_cast<llong>(mod)) : x_) {}
    mint &operator += (const mint &a) { x = ((x += a.x) >= mod) ? (x - mod) : x; return *this; }
    mint &operator -= (const mint &a) { x = ((x -= a.x) >= mod) ? (x + mod) : x; return *this; }
    mint &operator *= (const mint &a) { x = (static_cast<ullong>(x) * a.x) % mod; return *this; }
    mint &operator /= (const mint &a) { return (*this *= a.inv()); }
    mint pow(llong e) const {
        if (e < 0) return inv().pow(-e);
        mint a = *this, b = 1U; for (; e; e >>= 1) { if (e & 1) b *= a; a *= a; } return b;
    }

    mint inv() const {
        unsigned a = mod, b = x; int y = 0, z = 1;
        for (; b; ) { const unsigned q = a / b; const unsigned c = a - q * b; a = b; b = c; const int w = y - static_cast<int>(q) * z; y = z; z = w; }
        assert(a == 1U); return mint(y);
    }

    mint operator + () const { return *this; }
    mint operator - () const { mint a; a.x = x ? (mod - x) : 0U; return a; }
    mint operator + (const mint &a) const { return (mint(*this) += a); }
    mint operator - (const mint &a) const { return (mint(*this) -= a); }
    mint operator * (const mint &a) const { return (mint(*this) *= a); }
    mint operator / (const mint &a) const { return (mint(*this) /= a); }
    template <class T> friend mint operator + (T a, const mint &b) { return (mint(a) += b); }
    template <class T> friend mint operator - (T a, const mint &b) { return (mint(a) -= b); }
    template <class T> friend mint operator * (T a, const mint &b) { return (mint(a) *= b); }
    template <class T> friend mint operator / (T a, const mint &b) { return (mint(a) /= b); }
    explicit operator bool() const { return x; }
    bool operator == (const mint &a) const { return (x == a.x); }
    bool operator != (const mint &a) const { return (x != a.x); }
    friend std::ostream &operator << (std::ostream &os, const mint &a) { return os << a.x; }
};

typedef mint<1'000'000'007> Mint;

Mint dp[27][5001], C[5001][5001];
int cnt[26];

void solve() {
    string s; cin >> s;
    int n = s.size();

    for(char c: s) ++cnt[c - 'a'];

    for(int i = 0; i <= n; ++i) {
        C[i][0] = 1;
        for(int j = 1; j <= i; ++j) C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }

    dp[0][0] = 1;
    for(int c = 0, sum = 0; c < 26; sum += cnt[c++]) {
        int num = cnt[c];
        if (num == 0) {
            for(int j = 0; j <= n; ++j) dp[c + 1][j] = dp[c][j];
            continue;
        }

        for(int j = 0; j <= sum; ++j)
        for(int k = 1; k <= num; ++k)
            dp[c + 1][j + k] += dp[c][j] * C[j + k][k] * C[num - 1][k - 1];
    }

    Mint ans = 0;
    for(int i = n, sign = 1; i >= 0; --i, sign = -sign)
    ans += dp[26][i] * sign;

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int tests = 1; // cin >> tests;
    for(int test = 1; test <= tests; ++test) {
        solve();
    }

    return 0;
}
