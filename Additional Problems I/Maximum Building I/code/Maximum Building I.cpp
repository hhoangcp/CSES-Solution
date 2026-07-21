
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, L[1006], h[1006];
char S[1006];

int main() {
    scanf("%d%d", &n, &m);

    vector<int> Stack; int ans = 0;
    for(int i = 1; i <= n; ++i) {
        scanf("%s", S+1);

        Stack.clear();
        for(int j = 1; j <= m; ++j) {
            if (S[j] == '*') h[j] = 0; else ++h[j];

            while (!Stack.empty() && h[Stack.back()] >= h[j]) Stack.pop_back();
            if (Stack.empty()) L[j] = 0; else L[j] = Stack.back();
            Stack.push_back(j);
        }

        Stack.clear();
        for(int j = m, Right; j >= 1; --j) {
            while (!Stack.empty() && h[Stack.back()] >= h[j]) Stack.pop_back();
            if (Stack.empty()) Right = m+1; else Right = Stack.back();
            Stack.push_back(j);

            if (S[j] == '.') ans = max(ans, h[j] * (Right - L[j] - 1));
        }
    }

    cout << ans;

    return 0;
}
