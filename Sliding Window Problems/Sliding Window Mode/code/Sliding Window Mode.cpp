#include <algorithm>
#include <iostream>
#include <cmath>
#include <deque>
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

int a[200006];

void solve() {
    int n, k; cin >> n >> k;

    map<int, int> cnt;
    set<pii> S;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (cnt.count(a[i])) S.erase(pii(cnt[a[i]], -a[i]));
        S.insert(pii(++cnt[a[i]], -a[i]));
        if (i > k) {
            S.erase(pii(cnt[a[i - k]], -a[i - k]));
            if (--cnt[a[i - k]] == 0) cnt.erase(a[i - k]);
            else S.insert(pii(cnt[a[i - k]], -a[i - k]));
        }

        if (i >= k)
            cout << -S.rbegin()->snd << ' ';
    }

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
