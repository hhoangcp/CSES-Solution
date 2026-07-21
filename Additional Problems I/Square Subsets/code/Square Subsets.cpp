#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <climits>
#include <array>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <deque>
#include <chrono>
#include <bitset>
#include <iomanip>
#include <stack>
#include <complex>
#include <tuple>
#include <cassert>
#include <random>
#include <functional>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int128 __int128
#define uint128 __uint128_t
#define llong long long
#define ullong unsigned llong
#define int64 long long
#define uint64 uint64_t
#define ll llong
#define ull ullong
#define uint unsigned int
#define sint short int
#define usint unsigned sint
#define eb emplace_back
#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define fst first
#define snd second
#define pii pair<int, int>
#define pli pair<ll, int>
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define tiii tuple<int, int, int>
#define pld pair<ld, ld>
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()

using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

const int MAX_VAL = 5005;
const int P_COUNT = 670;
const int MOD = 1e9 + 7;

vector<int> primes;
bitset<P_COUNT> basis[P_COUNT];
int sz = 0;

void sieve() {
    vector<bool> is_p(MAX_VAL, true);
    is_p[0] = is_p[1] = false;
    for (int i = 2; i * i < MAX_VAL; ++i) {
        if (is_p[i]) {
            for (int j = i * i; j < MAX_VAL; j += i)
                is_p[j] = false;
        }
    }
    for (int i = 2; i < MAX_VAL; ++i) {
        if (is_p[i]) primes.push_back(i);
    }
}

void insert_mask(bitset<P_COUNT> mask) {
    for (int i = 0; i < primes.size(); ++i) {
        if (!mask[i]) continue;
        if (!basis[i].any()) {
            basis[i] = mask;
            sz++;
            return;
        }
        mask ^= basis[i];
    }
}

ll power(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}

void solve() {
    sieve();
    int n; cin >> n;

    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        bitset<P_COUNT> mask;
        for (int j = 0; j < primes.size(); ++j) {
            if (primes[j] > x) break;
            int cnt = 0;
            while (x % primes[j] == 0) {
                cnt++;
                x /= primes[j];
            }
            if (cnt & 1) mask[j] = 1;
        }
        insert_mask(mask);
    }

    cout << power(2, n - sz) << "\n";
}

int main() {
    //freopen("test_input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tests = 1; //cin >> tests;
    for (int i = 0; i < tests; ++i) {
        solve();
    }

    return 0;
}
