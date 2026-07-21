
#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
template<unsigned mod_>
struct mint {
    static constexpr unsigned mod = mod_;
    unsigned x;
    constexpr mint():x(0U){}
    constexpr mint(unsigned x_):x(x_%mod) {}
    constexpr mint(ull x_):x(x_%mod) {}
    constexpr mint(int x_):x(((x_%=static_cast<int>(mod))<0)?(x_+static_cast<int>(mod)):x_){}
    constexpr mint(ll x_):x(((x_%=static_cast<ll>(mod))<0)?(x_+static_cast<ll>(mod)):x_){}
    mint &operator+=(const mint &a){x=((x+=a.x)>=mod)?(x-mod):x;return *this;}
    mint &operator-=(const mint &a){x=((x-=a.x)>=mod)?(x+mod):x;return *this;}
    mint &operator*=(const mint &a){x=(static_cast<ull>(x)*a.x)%mod;return *this;}
    mint &operator/=(const mint &a){return (*this*=a.inv());}
    mint pow(ll e) const {
        if (e < 0) return inv().pow(-e);
        mint a=*this,b=1U; for(;e;e>>=1){if(e&1)b*=a;a*=a;} return b;
    }
    mint inv() const {
        unsigned a=mod,b=x; int y=0,z=1;
        for (;b;) {const unsigned q=a/b;
        const unsigned c=a-q*b;a=b;b=c;
        const int w=y-static_cast<int>(q)*z;y=z;z=w;}
        assert(a==1U); return mint(y);
    }
    int sqrt() const {
        mint st=pow((mod-1)/2);
        if (st.x!=1) { if(x==0) return 0; else return -1;}
        int s=mod-1,r=0;
        while (~s&1) s>>=1,++r;
        mint n=2; while (n.pow((mod-1)/2).x==1) n=n.x+1;
        for(mint x = pow((s+1)/2),b=pow(s),g=n.pow(s);;) {
            if (b.x==1) return min(x.x,mod-x.x);
            int m=0;for(mint t=b;t.x!=1;t*=t) ++m;
            for(int i=r-m-1;i>=1;--i) g*=g;
            x*=g,g*=g,b*=g,r=m;
        }
    }
    mint operator + () const {return *this;}
    mint operator - () const {mint a;a.x=x?(mod-x):0U; return a;}
    mint operator + (const mint &a) const {return (mint(*this)+=a);}
    mint operator - (const mint &a) const {return (mint(*this)-=a);}
    mint operator * (const mint &a) const {return (mint(*this)*=a);}
    mint operator / (const mint &a) const {return (mint(*this)/=a);}
    template <class T> friend mint operator + (T a, const mint &b) {return (mint(a)+=b);}
    template <class T> friend mint operator - (T a, const mint &b) {return (mint(a)-=b);}
    template <class T> friend mint operator * (T a, const mint &b) {return (mint(a)*=b);}
    template <class T> friend mint operator / (T a, const mint &b) {return (mint(a)/=b);}
    explicit operator bool() const { return x; }
    bool operator == (const mint &a) const {return (x==a.x);}
    bool operator != (const mint &a) const {return (x!=a.x);}
    friend ostream &operator << (ostream &os, const mint &a) {return os << a.x;}
};

typedef mint<1'000'000'007> Mint;
typedef vector<Mint> arr;
typedef vector<arr> mat;
tuple<int,arr,mat> solve_linear(mat a, arr b) {
    int n=a.size(),m=a[0].size();
    for(int i=0;i<n;++i) a[i].push_back(b[i]);
    vector<int> fix(m,-1); int k = 0, R = m;
    for(int i=0;i<m;++i) {
        int j=k; for(;j<n;++j) if(a[j][i] != 0) break;
        if(j==n) continue;
        fix[i]=k;--R;swap(a[k],a[j]);
        Mint *u=a[k].data(), x=u[i].inv();
        for(j=i;j<=m;++j) u[j]*=x;
        for(arr &v:a) if(v.data()!=a[k].data()) {
            x=-v[i];
            for(j=i;j<=m;++j) v[j]+=x*u[j];
        }
        ++k;
    }
    for(int i=k;i<n;++i) if(a[i][m]) return {-1,{},{}};
    arr c(m); mat d;
    for(int i=0;i<m;++i) if(fix[i]!=-1) c[i]=a[fix[i]][m];
    for(int i=0;i<m;++i) if(fix[i]==-1) {
        arr t(m); t[i]=1;
        for(int j=0;j<m;++j) if(fix[j]!=-1) t[j]=-a[fix[j]][i];
        d.push_back(t);
    }
    return {R,c,d};
}

void solve() {
    int n, m; cin >> n >> m;
    mat a(n, arr(m, 0)); arr b(n, 0);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) cin >> a[i][j].x;
        cin >> b[i].x;
    }

    auto [R, c, d] = solve_linear(a, b);

    if (R == -1) {
        cout << "-1\n";
        return;
    }

    for(int i = 0; i < m; ++i) cout << c[i] << ' ';
    cout << '\n';
}

int main() {
    int tests = 1; //cin >> tests;
    while (tests--) solve();

    return 0;
}