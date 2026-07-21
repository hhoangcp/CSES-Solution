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

int a[1006];

void solve() {
    int n; cin >> n;

    for (int l = 0; (1 << l) <= n; ++l) {
        string s = "";

        for (int i = 1; i <= n; ++i)
            if (i & (1 << l)) s.pub('1'); else s.pub('0');

        cout << "? " << s << endl;
        string ans; cin >> ans;

        for (int i = 1; i <= n; ++i)
            if (ans[i - 1] == '1') a[i] += (1 << l);
    }

    cout << "! ";
    for (int i = 1; i <= n; ++i) cout << a[i] << " ";
    cout << endl;
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
