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

vector<int> num, res;
int n;

void backtrack() {
    if (num.empty()) {
        for (int x : res) { std::cout << x << " \n"[x == res.back()]; }
        exit(0);
    }

    for (int i = (int)num.size() - 1; i >= 0; --i) {
        int x = num[i];
        if (res.empty() || abs(res.back() - x) != 1) {
            num.erase(num.begin() + i);
            res.push_back(x);
            backtrack();
            res.pop_back();
            num.insert(num.begin() + i, x);
        }
    }
}

void solve() {
    cin >> n;
    if (n == 1) {
        cout << "1\n";
        return;
    }

    if (n < 4) {
        cout << "NO SOLUTION\n";
        return;
    }

    for (int i = n; i >= 1; --i)
        num.push_back(i);

    backtrack();
}

int main() {
    //freopen("test_input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tests = 1;
    for (int i = 0; i < tests; ++i) {
        solve();
    }

    return 0;
}
