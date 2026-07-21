
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int mod = 1e9+7;
int n, k, dp[5006];
string S;

typedef struct TNode {
    TNode *x[26];
    bool End;
} *node;

node New_node() {
    node P = new TNode();

    P->End = false;
    for(int i = 0; i < 26; ++i) P->x[i] = NULL;

    return P;
}

node root = New_node();

void Insert(const string &a) {
    node cur = root;

    for(int i = 0; i < (int) a.size(); ++i) {
        int c = a[i] - 'a';

        if (!cur->x[c]) cur->x[c] = New_node();
        cur = cur->x[c];
    }

    cur->End = true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> S; n = S.size();
    cin >> k;
    while (k--) {
        string T; cin >> T;
        Insert(T);
    }

    dp[n] = 1;
    for(int i = n-1; i >= 0; --i) {
        dp[i] = 0;

        node cur = root;
        for(int j = i; j < n; ++j) {
            int c = S[j] - 'a';

            if (!cur->x[c]) break;
            cur = cur->x[c];

            if (cur->End) dp[i] = (dp[i] + dp[j+1]) % mod;
        }
    }

    cout << dp[0];

    return 0;
}
