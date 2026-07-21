#include <algorithm>
#include <iostream>
#include <vector>
#include <cassert>
#define ll long long
#define ull unsigned long long

using namespace std;

template<unsigned mod_>
struct mint {
    static constexpr unsigned mod = mod_;
    unsigned x;
    constexpr mint() : x(0U) {}
    constexpr mint(unsigned x_) : x(x_ % mod) {}
    constexpr mint(ull x_) : x(x_ % mod) {}
    constexpr mint(int x_) : x(((x_ %= static_cast<int>(mod)) < 0) ? (x_ + static_cast<int>(mod)) : x_) {}
    constexpr mint(ll x_) : x(((x_ %= static_cast<ll>(mod)) < 0) ? (x_ + static_cast<ll>(mod)) : x_) {}
    mint &operator += (const mint &a) { x = ((x += a.x) >= mod) ? (x - mod) : x; return *this; }
    mint &operator -= (const mint &a) { x = ((x -= a.x) >= mod) ? (x + mod) : x; return *this; }
    mint &operator *= (const mint &a) { x = (static_cast<ull>(x) * a.x) % mod; return *this; }
    mint &operator /= (const mint &a) { return (*this *= a.inv()); }
    mint pow(ll e) const {
        if (e < 0) return inv().pow(-e);
        mint a = *this, b = 1U; for (; e; e >>= 1) { if (e & 1) b *= a; a *= a; } return b;
    }

    mint inv() const {
        unsigned a = mod, b = x; int y = 0, z = 1;
        for (; b; ) { const unsigned q = a / b; const unsigned c = a - q * b; a = b; b = c; const int w = y - static_cast<int>(q) * z; y = z; z = w; }
        assert(a == 1U); return mint(y);
    }

    int sqrt() const {
        mint st = pow((mod - 1) / 2);
        if (st.x != 1) { if (x == 0) return 0; else return -1; }
        int s = mod - 1, r = 0;
        while (~s & 1) s >>= 1, ++r;
        mint n = 2; while (n.pow((mod - 1) / 2).x == 1) n = n.x + 1;
        for(mint x = pow((s + 1) / 2), b = pow(s), g = n.pow(s);;) {
            if (b.x == 1) return min(x.x, mod - x.x);
            int m = 0; for(mint t = b; t.x != 1; t *= t) ++m;
            for(int i = r - m - 1; i >= 1; --i) g *= g;
            x *= g, g *= g, b *= g, r = m;
        }
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

int nxt[200006];
bool used[200006];

int f[200006], prime[20006], sz = 0;
int e[200006];

Mint power(Mint a, int n) {
    Mint ans = 1;
    for (; n > 0; n >>= 1) {
        if (n & 1) ans *= a;
        a *= a;
    }
    return ans;
}

void sieve(int n) {
    for (int i = 0; i <= n; ++i) f[i] = 0;
    sz = 0;

    for (int i = 2; i <= n; ++i) {
        if (f[i] == 0) f[i] = prime[++sz] = i;
        for (int j = 1; j <= sz && prime[j] <= f[i] && prime[j] * i <= n; ++j)
            f[prime[j] * i] = prime[j];
    }
}

void solve() {
    int n; cin >> n; sieve(n);
    for (int i = 1; i <= n; ++i) cin >> nxt[i];

    for (int i = 1; i <= n; ++i)
        if (!used[i]) {
            int len = 0;

            while (!used[i]) {
                used[i] = true;
                ++len; i = nxt[i];
            }

            int val = len;
            while (val > 1) {
                int p = f[val], num = 0;
                while (val % p == 0) {
                    val /= p;
                    ++num;
                }

                e[p] = max(e[p], num);
            }
        }

    Mint ans = 1;
    for (int i = 1; i <= sz; ++i) ans *= power(prime[i], e[prime[i]]);

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tests = 1; //cin >> tests;
    for (int i = 0; i < tests; ++i) {
        solve();
    }
}
