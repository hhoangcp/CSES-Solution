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

void solve() {
    int n; cin >> n;

    int l = 2, r = n;
    cout << "? " << 1 << endl;
    char ch; cin >> ch;
    cout << "? " << n << endl;
    char chN; cin >> chN;
    if (ch == chN) {
        cout << "! " << n << endl;
        return;
    }

    while (l < r) {
        int mid = (l + r) >> 1;
        cout << "? " << mid << endl;
        char chMid; cin >> chMid;
        bool ok = true;
        if ((mid - 1) % 2) {
            if (ch == chMid) ok = false;
        } else {
            if (ch != chMid) ok = false;
        }

        if (ok) {
            l = mid + 1;
        } else r = mid;
    }

    cout << "! " << l - 1 << endl;
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
