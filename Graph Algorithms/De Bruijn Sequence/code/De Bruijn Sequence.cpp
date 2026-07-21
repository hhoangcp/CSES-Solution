
#include <iostream>
#include <vector>

using namespace std;

int n, ptr[1 << 16];
vector<int> edges;

void DFS(int u) {
    while (ptr[u] < 2) {
        int c = ptr[u]++;
        DFS(((u << 1) | c) & ((1 << (n - 1)) - 1));
        edges.push_back(c);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;

    DFS(0);

    string ans = "";
    for (int i = 0; i < (int)edges.size(); ++i)
        ans += char(edges[i] + '0');
    ans += string(n - 1, '0');

    cout << ans;

    return 0;
}
