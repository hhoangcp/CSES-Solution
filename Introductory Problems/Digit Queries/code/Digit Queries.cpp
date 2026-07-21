#include <bits/stdc++.h>
#define uint128 __uint128_t
#define int128 __int128
#define ld long double
#define ll long long
#define ull unsigned ll
#define uint unsigned int
#define sint short int
#define eb emplace_back
#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define fst first
#define snd second
#define mp make_pair
#define mt make_tuple
#define pii pair<int, int>
#define pil pair<ll, int>
#define pli pair<int, ll>
#define pll pair<ll, ll>
#define tiii tuple<int, int, int>
#define pld pair<ld, ld>
#define all(x) x.begin(), x.end()

using namespace std;

ll power[19];
 
ll Find(ll k) {
    int cur = 1;
    for(; k > 9LL * cur * power[cur - 1]; k -= 9LL * cur * power[cur - 1], ++cur);
 
    ll num = power[cur - 1];
    --k; num += k / cur; k %= cur;
 
    for(int i = cur - 1; i > k; --i) num /= 10;
    return num % 10;
 }
 

void solve() {
    power[0] = 1;
    for(int i = 1; i <= 18; ++i) power[i] = power[i - 1] * 10;

    int q; cin >> q;
    while (q--) {
        ll k; cin >> k;
        cout << Find(k) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int tests = 1; //cin >> tests;
    for(int test = 1; test <= tests; ++test) {
        solve();
    }

    return 0;
}
