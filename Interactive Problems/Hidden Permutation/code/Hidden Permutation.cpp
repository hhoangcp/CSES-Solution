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

int a[1006], b[1006];

void merge_sort(int l, int r) {
    if (l >= r) return;

    int mid = (l + r) >> 1;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);

    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r) {
        cout << "? " << a[i] << ' ' << a[j] << endl;
        string ans; cin >> ans;

        if (ans == "YES") b[k++] = a[i++];
        else b[k++] = a[j++];
    }

    while (i <= mid) b[k++] = a[i++];
    while (j <= r) b[k++] = a[j++];

    for (i = l; i <= r; i++) a[i] = b[i];
}

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) a[i] = i;

    merge_sort(1, n);
    cout << "! ";
    for (int i = 1; i <= n; ++i) b[a[i]] = i;
    for (int i = 1; i <= n; ++i) cout << b[i] << ' ';
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
