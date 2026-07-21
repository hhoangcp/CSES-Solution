
#include <cstdio>
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

struct Line_X {
    int x, l, r;

    bool operator < (const Line_X &other) {
        return x < other.x;
    }
} P[100006];

struct Line_Y {
    int y, x, val;

    bool operator < (const Line_Y &other) {
        return x < other.x;
    }
} Q[200006];

llong res = 0;
int bit[400006];
int srt_x[600006], cnt_x = 0;
int srt_y[400006], cnt_y = 0;
int cnt_P = 0, cnt_Q = 0, n;

void Update(int p, int val) {
    for(; p <= cnt_y; p += (p & (-p))) bit[p] += val;
}

int Query(int p) {
    int num = 0;
    for(; p > 0; p -= (p & (-p))) num += bit[p];
    return num;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;
    while (n--) {
        int x, y, u, v; cin >> x >> y >> u >> v;
        if (x == u) P[++cnt_P] = {x, min(y, v), max(y, v)};
        else {
            Q[++cnt_Q] = {y, min(x, u), 1};
            Q[++cnt_Q] = {y, max(x, u)+1, -1};
        }

        srt_x[++cnt_x] = x;
        srt_x[++cnt_x] = u;
        srt_x[++cnt_x] = max(x, u)+1;
        srt_y[++cnt_y] = y;
        srt_y[++cnt_y] = v;
    }

    sort(P+1, P+cnt_P+1);
    sort(Q+1, Q+cnt_Q+1);
    sort(srt_x+1, srt_x+cnt_x+1);
    sort(srt_y+1, srt_y+cnt_y+1);
    cnt_x = unique(srt_x+1, srt_x+cnt_x+1) - srt_x-1;
    cnt_y = unique(srt_y+1, srt_y+cnt_y+1) - srt_y-1;

    int cur_P = 1, cur_Q = 1;
    for(int i=1; i<=cnt_x; ++i) {
        while (cur_Q <= cnt_Q && Q[cur_Q].x == srt_x[i]) {
            Q[cur_Q].y = lower_bound(srt_y+1, srt_y+cnt_y+1, Q[cur_Q].y) - srt_y;
            Update(Q[cur_Q].y, Q[cur_Q].val);
            ++cur_Q;
        }

        while (cur_P <= cnt_P && P[cur_P].x == srt_x[i]) {
            P[cur_P].l = lower_bound(srt_y+1, srt_y+cnt_y+1, P[cur_P].l) - srt_y;
            P[cur_P].r = lower_bound(srt_y+1, srt_y+cnt_y+1, P[cur_P].r) - srt_y;
            res += Query(P[cur_P].r) - Query(P[cur_P].l-1);
            ++cur_P;
        }
    }

    cout << res;

    return 0;

}
