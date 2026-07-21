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
 
char last[3006][3006];
vector<int> row[26][3006];
 
void solve() {
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            last[i][j] = 26;
            char c; cin >> c;
            row[c - 'A'][i].push_back(j);
        }
 
    for (int c = 0; c < k; ++c) {
        bool ans = false;
 
        for (int i = 0; i < n && !ans; ++i) {
            vector<int> &vec = row[c][i];
 
            for (int l = 0; l < (int) vec.size() && !ans; ++l)
                for (int r = l + 1; r < (int) vec.size() && !ans; ++r) {
                    int u = vec[l], v = vec[r];
                    if (last[u][v] == c) ans = true;
                    else last[u][v] = c;
                }
        }
 
        if (ans) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
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
