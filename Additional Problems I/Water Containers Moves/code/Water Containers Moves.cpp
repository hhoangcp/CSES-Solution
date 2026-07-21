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

struct State {
    int a, b;
};

struct Step {
    int from_a, from_b;
    int type;
};

ll dist[1005][1005];
Step trace[1005][1005];


void solve() {
int cap_a, cap_b, target;
    cin >> cap_a >> cap_b >> target;

    for (int i = 0; i <= cap_a; i++)
        for (int j = 0; j <= cap_b; j++)
            dist[i][j] = INF;

    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<tuple<ll, int, int>>> pq;

    dist[0][0] = 0;
    pq.push({0, 0, 0});

    int final_a = -1, final_b = -1;

    while (!pq.empty()) {
        auto [d, u_a, u_b] = pq.top();
        pq.pop();

        if (d > dist[u_a][u_b]) continue;

        if (u_a == target) {
            final_a = u_a;
            final_b = u_b;
            break;
        }

        int next_a, next_b;
        ll cost;

        // 1. FILL A
        next_a = cap_a; next_b = u_b;
        cost = cap_a - u_a;
        if (cost > 0 && dist[next_a][next_b] > d + cost) {
            dist[next_a][next_b] = d + cost;
            trace[next_a][next_b] = {u_a, u_b, 1};
            pq.push({dist[next_a][next_b], next_a, next_b});
        }

        // 2. FILL B
        next_a = u_a; next_b = cap_b;
        cost = cap_b - u_b;
        if (cost > 0 && dist[next_a][next_b] > d + cost) {
            dist[next_a][next_b] = d + cost;
            trace[next_a][next_b] = {u_a, u_b, 2};
            pq.push({dist[next_a][next_b], next_a, next_b});
        }

        // 3. EMPTY A
        next_a = 0; next_b = u_b;
        cost = u_a;
        if (cost > 0 && dist[next_a][next_b] > d + cost) {
            dist[next_a][next_b] = d + cost;
            trace[next_a][next_b] = {u_a, u_b, 3};
            pq.push({dist[next_a][next_b], next_a, next_b});
        }

        // 4. EMPTY B
        next_a = u_a; next_b = 0;
        cost = u_b;
        if (cost > 0 && dist[next_a][next_b] > d + cost) {
            dist[next_a][next_b] = d + cost;
            trace[next_a][next_b] = {u_a, u_b, 4};
            pq.push({dist[next_a][next_b], next_a, next_b});
        }

        // 5. MOVE A -> B
        int move_amt = min(u_a, cap_b - u_b);
        next_a = u_a - move_amt; next_b = u_b + move_amt;
        cost = move_amt;
        if (cost > 0 && dist[next_a][next_b] > d + cost) {
            dist[next_a][next_b] = d + cost;
            trace[next_a][next_b] = {u_a, u_b, 5};
            pq.push({dist[next_a][next_b], next_a, next_b});
        }

        // 6. MOVE B -> A
        move_amt = min(u_b, cap_a - u_a);
        next_a = u_a + move_amt; next_b = u_b - move_amt;
        cost = move_amt;
        if (cost > 0 && dist[next_a][next_b] > d + cost) {
            dist[next_a][next_b] = d + cost;
            trace[next_a][next_b] = {u_a, u_b, 6};
            pq.push({dist[next_a][next_b], next_a, next_b});
        }
    }

    if (final_a == -1) {
        cout << -1 << "\n";
    } else {
        // Truy vết ngược từ đích về nguồn
        vector<string> moves;
        int curr_a = final_a;
        int curr_b = final_b;

        while (curr_a != 0 || curr_b != 0) {
            Step s = trace[curr_a][curr_b];
            if (s.type == 1) moves.push_back("FILL A");
            else if (s.type == 2) moves.push_back("FILL B");
            else if (s.type == 3) moves.push_back("EMPTY A");
            else if (s.type == 4) moves.push_back("EMPTY B");
            else if (s.type == 5) moves.push_back("MOVE A B");
            else if (s.type == 6) moves.push_back("MOVE B A");

            curr_a = s.from_a;
            curr_b = s.from_b;
        }

        reverse(moves.begin(), moves.end());

        cout << moves.size() << " " << dist[final_a][final_b] << "\n";
        for (const string &mv : moves) {
            cout << mv << "\n";
        }
    }
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
