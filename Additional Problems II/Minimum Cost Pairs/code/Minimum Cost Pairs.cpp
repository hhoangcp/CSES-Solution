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

const ll INF = 1e18;
const int MAXN = 200005;

struct Node {
    ll val;
    int id;
    bool operator>(const Node& other) const {
        return val > other.val;
    }
};

ll D[MAXN];
int L[MAXN], R[MAXN];
bool removed[MAXN];

void solve() {
    int n; cin >> n;

    vector<ll> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    sort(x.begin(), x.end());

    priority_queue<Node, vector<Node>, greater<Node>> pq;

    for (int i = 0; i < n - 1; i++) {
        D[i + 1] = x[i + 1] - x[i];
        L[i + 1] = i;
        R[i + 1] = i + 2;
        pq.push({D[i + 1], i + 1});
        removed[i + 1] = false;
    }

    D[0] = INF;
    D[n] = INF;
    R[0] = 1;
    L[n] = n - 1;

    ll current_cost = 0;
    vector<ll> results;

    for (int k = 1; k <= n / 2; k++) {
        while (true) {
            Node top = pq.top();
            pq.pop();

            if (removed[top.id] || top.val != D[top.id]) continue;

            current_cost += top.val;
            results.push_back(current_cost);

            int i = top.id;
            int l = L[i];
            int r = R[i];

            ll newVal = D[l] + D[r] - D[i];
            D[i] = newVal;

            if (l != 0) removed[l] = true;
            if (r != n) removed[r] = true;

            L[i] = L[l];
            R[i] = R[r];

            if (L[l] != 0) R[L[l]] = i;
            else R[0] = i;

            if (R[r] != n) L[R[r]] = i;
            else L[n] = i;

            pq.push({D[i], i});

            break;
        }
    }

    for (int i = 0; i < (int)results.size(); i++) {
        cout << results[i] << ' ';
    }

    cout << '\n';
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
