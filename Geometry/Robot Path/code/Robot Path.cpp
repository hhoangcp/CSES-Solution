
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define llong long long

using namespace std;

set<llong> Seg[400016];

void Update(int id, int l, int r, int u, int v, llong val) {
    if (l > v || r < u) return;
    if (u <= l && r <= v) {
        Seg[id].insert(val);
        return;
    }

    int mid = (l + r) >> 1;

    Update(id*2+1, l, mid, u, v, val);
    Update(id*2+2, mid+1, r, u, v, val);
}

llong Query_min(int id, int l, int r, int p, llong Greater) {
    if (l > p || r < p) return 2e18;

    llong ans = 2e18;
    set<llong>::iterator it = Seg[id].upper_bound(Greater);
    if (it != Seg[id].end()) ans = (*it);

    if (l == r) return ans;

    int mid = (l + r) >> 1;
    ans = min(ans, Query_min(id*2+1, l, mid, p, Greater));
    ans = min(ans, Query_min(id*2+2, mid+1, r, p, Greater));

    return ans;
}

llong Query_max(int id, int l, int r, int p, llong Less) {
    if (l > p || r < p) return -2e18;

    llong ans = -2e18;
    set<llong>::iterator it = Seg[id].lower_bound(Less);
    if (it != Seg[id].begin()) {
        --it;
        ans = (*it);
    }

    if (l == r) return ans;

    int mid = (l + r) >> 1;
    ans = max(ans, Query_max(id*2+1, l, mid, p, Less));
    ans = max(ans, Query_max(id*2+2, mid+1, r, p, Less));

    return ans;
}

struct Data {
    llong x, y, u, v;
} D[100006];

vector<llong> sorted_x, sorted_y;
llong Jump[100006];
int n;

int main() {
    cin >> n;

    llong x = 0, y = 0; sorted_x.push_back(0); sorted_y.push_back(0);
    char pre = '0';

    for(int i = 1; i <= n; ++i) {
        int delta; char c;
        cin >> c >> delta;

        if (c == 'U') D[i] = {x, y, x, y+delta}, y += delta;
        if (c == 'D') D[i] = {x, y, x, y-delta}, y -= delta;
        if (c == 'L') D[i] = {x, y, x-delta, y}, x -= delta;
        if (c == 'R') D[i] = {x, y, x+delta, y}, x += delta;

        if ((c == 'U' && pre == 'D') || (c == 'D' && pre == 'U')) {
            n = i - 1;
            break;
        }

        if ((c == 'L' && pre == 'R') || (c == 'R' && pre == 'L')) {
            n = i - 1;
            break;
        }

        sorted_x.push_back(x);
        sorted_y.push_back(y);

        pre = c;
    }

    sort(sorted_x.begin(), sorted_x.end());
    sort(sorted_y.begin(), sorted_y.end());

    sorted_x.resize(unique(sorted_x.begin(), sorted_x.end()) - sorted_x.begin());
    sorted_y.resize(unique(sorted_y.begin(), sorted_y.end()) - sorted_y.begin());

    for(int i = 1; i <= n; ++i) {
        D[i].x = lower_bound(sorted_x.begin(), sorted_x.end(), D[i].x) - sorted_x.begin();
        D[i].u = lower_bound(sorted_x.begin(), sorted_x.end(), D[i].u) - sorted_x.begin();
        D[i].y = lower_bound(sorted_y.begin(), sorted_y.end(), D[i].y) - sorted_y.begin();
        D[i].v = lower_bound(sorted_y.begin(), sorted_y.end(), D[i].v) - sorted_y.begin();
    }

    int Last = n;

    for(int i = 1; i <= n; ++i)
    if (D[i].x != D[i].u) Update(0, 0, sorted_x.size()-1, min(D[i].x, D[i].u), max(D[i].x, D[i].u), sorted_y[D[i].y]);
    else {
        if (D[i].y < D[i].v) {
            llong Y = Query_min(0, 0, sorted_x.size()-1, D[i].x, sorted_y[D[i].y]);

            if (Y > sorted_y[D[i].v]) Jump[i] = sorted_y[D[i].v] - sorted_y[D[i].y];
            else {
                Last = i;
                Jump[i] = Y - sorted_y[D[i].y];
                break;
            }
        } else {
            llong Y = Query_max(0, 0, sorted_x.size()-1, D[i].x, sorted_y[D[i].y]);

            if (Y < sorted_y[D[i].v]) Jump[i] = sorted_y[D[i].y] - sorted_y[D[i].v];
            else {
                Last = i;
                Jump[i] = sorted_y[D[i].y] - Y;
                break;
            }
        }

        Update(0, 0, sorted_x.size()-1, D[i].x, D[i].x, sorted_y[D[i].y]);
        Update(0, 0, sorted_x.size()-1, D[i].x, D[i].x, sorted_y[D[i].v]);
    }

    for(int i = 0; i <= (int) (4 * sorted_y.size()); ++i) Seg[i].clear();

    for(int i = 1; i <= Last; ++i)
    if (D[i].y != D[i].v) Update(0, 0, sorted_y.size()-1, min(D[i].y, D[i].v), max(D[i].y, D[i].v), sorted_x[D[i].x]);
    else {
        if (D[i].x < D[i].u) {
            llong X = Query_min(0, 0, sorted_y.size()-1, D[i].y, sorted_x[D[i].x]);

            if (X > sorted_x[D[i].u]) Jump[i] = sorted_x[D[i].u] - sorted_x[D[i].x];
            else {
                Last = i;
                Jump[i] = X - sorted_x[D[i].x];
                break;
            }
        } else {
            llong X = Query_max(0, 0, sorted_y.size()-1, D[i].y, sorted_x[D[i].x]);

            if (X < sorted_x[D[i].u]) Jump[i] = sorted_x[D[i].x] - sorted_x[D[i].u];
            else {
                Last = i;
                Jump[i] = sorted_x[D[i].x] - X;
                break;
            }
        }

        Update(0, 0, sorted_y.size()-1, D[i].y, D[i].y, sorted_x[D[i].x]);
        Update(0, 0, sorted_y.size()-1, D[i].y, D[i].y, sorted_x[D[i].u]);
    }

    llong ans = 0;
    for(int i = 1; i <= Last; ++i) ans += Jump[i];

    cout << ans;

    return 0;
}
