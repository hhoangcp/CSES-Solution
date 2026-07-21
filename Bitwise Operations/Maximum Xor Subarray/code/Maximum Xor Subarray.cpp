
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct TNode {
    TNode *Next[2];
    int value;
} *node;

node New_node() {
    node P = new TNode();
    P->Next[0] = P->Next[1] = NULL;
    P->value = 0;

    return P;
}

node root = New_node();

void Add(int x) {
    node cur = root;

    for(int i = 30; i >= 0; --i) {
        int c = (int) ((x & (1 << i)) > 0);

        if (!cur->Next[c]) cur->Next[c] = New_node();
        cur = cur->Next[c];
    }

    cur->value = x;
}

int Query(int x) {
    node cur = root;

    for(int i = 30; i >= 0; --i) {
        int c = (int) ((x & (1 << i)) > 0);

        if (cur->Next[1-c]) cur = cur->Next[1-c];
        else if (cur->Next[c]) cur = cur->Next[c];
        else return 0;
    }

    return x ^ cur->value;
}

int n;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n; Add(0);

    int prefix = 0, res = 0;
    for(int i = 1; i <= n; ++i) {
        int a; cin >> a; prefix ^= a;

        res = max(res, Query(prefix));
        Add(prefix);
    }

    cout << res;

    return 0;
}
