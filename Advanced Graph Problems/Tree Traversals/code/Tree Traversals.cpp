
#include <iostream>
#include <algorithm>

using namespace std;

int PreOrder[200006], InOrder[200006], pos[200006];
int n, cur = 1;

void PostOrder(int Left = 1, int Right = n) {
    if (Left > Right) {
        --cur;
        return;
    }

    int Mid = pos[PreOrder[cur]];

    ++cur; PostOrder(Left, Mid-1);
    ++cur; PostOrder(Mid+1, Right);

    cout << InOrder[Mid] << ' ';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> PreOrder[i];
    for(int i = 1; i <= n; ++i) {
        cin >> InOrder[i];
        pos[InOrder[i]] = i;
    }

    PostOrder();

    return 0;
}
