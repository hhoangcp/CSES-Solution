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

const int MOD = 1e9 + 7;

int n;
vector<long long> a, b;
vector<long long> prefA, prefB;

int best_i = 1, best_j = 1;

bool check(double x) {
    double max_val_A = -1e18;
    int current_best_i = -1;

    for (int i = 1; i <= n; ++i) {
        double val = prefA[i] - x * i;
        if (val > max_val_A) {
            max_val_A = val;
            current_best_i = i;
        }
    }

    double max_val_B = -1e18;
    int current_best_j = -1;

    for (int j = 1; j <= n; ++j) {
        double val = prefB[j] - x * j;
        if (val > max_val_B) {
            max_val_B = val;
            current_best_j = j;
        }
    }

    if (max_val_A + max_val_B >= 0) {
        best_i = current_best_i;
        best_j = current_best_j;
        return true;
    }

    return false;
}

void solve() {
    if (!(cin >> n)) return;

    a.resize(n + 1);
    b.resize(n + 1);
    prefA.resize(n + 1, 0);
    prefB.resize(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        prefA[i] = prefA[i-1] + a[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        prefB[i] = prefB[i-1] + b[i];
    }

    double low = 0.0, high = 1e9 + 7;

    for (int iter = 0; iter < 80; iter++) {
        double mid = (low + high) / 2;
        if (check(mid)) {
            low = mid;
        } else {
            high = mid;
        }
    }

    cout << best_i << " " << best_j << endl;
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
