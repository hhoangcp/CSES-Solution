
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, pos[200006], x[200006];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> m;
    for(int i=1; i<=n; ++i) {
        cin >> x[i];
        pos[x[i]] = i;
    }

    int Round = 1;
    for(int i=2; i<=n; ++i)
    if (pos[i] < pos[i-1]) ++Round;

    while (m--) {
        int a, b; cin >> a >> b;

        if (a == b) {
            cout << Round << '\n';
            continue;
        }

        swap(x[a], x[b]);
        a = x[a], b = x[b];
        if (a > b) swap(a, b);

        if (a > 1 && pos[a - 1] > pos[a]) --Round;
        if (b - a > 1 && pos[a + 1] < pos[a]) --Round;
        if (b - a > 1 && pos[b - 1] > pos[b]) --Round;
        if (b < n && pos[b + 1] < pos[b]) --Round;

        if (b - a == 1 && pos[a] > pos[b]) --Round;
        swap(pos[a], pos[b]);
        if (b - a == 1 && pos[a] > pos[b]) ++Round;

        if (a > 1 && pos[a - 1] > pos[a]) ++Round;
        if (b - a > 1 && pos[a + 1] < pos[a]) ++Round;
        if (b - a > 1 && pos[b - 1] > pos[b]) ++Round;
        if (b < n && pos[b + 1] < pos[b]) ++Round;

        cout << Round << '\n';
    }

    return 0;
}
