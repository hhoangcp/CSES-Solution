
#include <iostream>
#include <algorithm>
#include <vector>
#define llong long long

using namespace std;

llong ans[1006][1006], add[1006][1006], sub[1006][1006];
int n, m, Left[1006], h[1006];
char inp[1006];

void Update(int x, int y, int u, int v, int val) {
    ans[x][y] += val;
    ans[x][v+1] -= val;
    ans[u+1][y] -= val;
    ans[u+1][v+1] += val;
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) {
        scanf("%s", inp+1);

        vector<int> S;
        for(int j = 1; j <= m; ++j)
        if (inp[j] == '*') {
            h[j] = 0;

            S.clear();
            S.push_back(j);
        } else {
            ++h[j];

            while (!S.empty() && h[S.back()] > h[j]) S.pop_back();
            if (S.empty()) Left[j] = 1; else Left[j] = S.back() + 1;

            S.push_back(j);
        }

        S.clear();

        for(int j = m; j >= 1; --j)
        if (inp[j] == '*') {
            S.clear();
            S.push_back(j);
        } else {
            int Right;
            while (!S.empty() && h[S.back()] >= h[j]) S.pop_back();
            if (S.empty()) Right = m; else Right = S.back() - 1;

            Update(1, 1, h[j], j - Left[j] + 1, 1);
            Update(1, 2, h[j], Right - j + 1, 1);

            ++add[h[j]][3]; --add[h[j]][Right - j + 3];
            ++sub[h[j]][j - Left[j] + 3], --sub[h[j]][Right - Left[j] + 3];

            S.push_back(j);
        }
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            add[i][j] += add[i][j-1];
            sub[i][j] += sub[i][j-1];
        }

        for(int j = 1; j <= m; ++j) {
            add[i][j] += add[i][j-1];
            sub[i][j] += sub[i][j-1];
        }
    }

    for(int j = 1; j <= m; ++j)
    for(int i = n; i >= 1; --i) {
        add[i][j] += add[i+1][j];
        sub[i][j] += sub[i+1][j];
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            ans[i][j] += ans[i][j-1] + ans[i-1][j] - ans[i-1][j-1];
            cout << ans[i][j] + add[i][j] - sub[i][j] << ' ';
        }

        cout << '\n';
    }

    return 0;
}
