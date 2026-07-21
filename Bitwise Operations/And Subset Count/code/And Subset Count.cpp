#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <tuple>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <bitset>
#include <iomanip>
#include <sstream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int128 __int128
#define uint128 __uint128_t
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int, int>
#define pil pair<int, ll>
#define pli pair<ll, int>
#define pll pair<ll, ll>
#define fst first
#define snd second
#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define mp make_pair
#define mt make_tuple

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

const int H = 18;
const int MAX = 1 << H;
ll dp[MAX];
Mint ans[MAX];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        ++dp[x];
    }

    for (int i = 0; i < H; ++i)
        for (int mask = 0; mask < MAX; ++mask)
            if (mask & (1 << i)) dp[mask ^ (1 << i)] += dp[mask];

    for (int i = 0; i < MAX; ++i) ans[i] = Mint(2).pow(dp[i]) - 1;

    for (int i = 0; i < H; ++i)
        for (int mask = 0; mask < MAX; ++mask)
            if (mask & (1 << i)) ans[mask ^ (1 << i)] -= ans[mask];

    for (int i = 0; i <= n; ++i) cout << ans[i] << " ";
    cout << '\n';
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
