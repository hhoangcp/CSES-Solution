
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct Data {
    int Left_0, Right_0;
    int Left_1, Right_1;
    int longest;
    bool all_0, all_1;
} Seg[800006];

void Merge(Data &par, Data A, Data B) {
    par = {0, 0, 0, 0, 0, false, false};

    if (A.all_0 && B.all_0) {
        par.all_0 = true;
        par.longest = A.longest + B.longest;
        return;
    }

    if (A.all_1 && B.all_1) {
        par.all_1 = true;
        par.longest = A.longest + B.longest;
        return;
    }

    if (A.all_0) {
        par.Left_0 = A.longest + B.Left_0;
        par.Left_1 = 0;
    } else if (A.all_1) {
        par.Left_0 = 0;
        par.Left_1 = A.longest + B.Left_1;
    } else {
        par.Left_0 = A.Left_0;
        par.Left_1 = A.Left_1;
    }

    if (B.all_0) {
        par.Right_0 = A.Right_0 + B.longest;
        par.Right_1 = 0;
    } else if (B.all_1) {
        par.Right_0 = 0;
        par.Right_1 = A.Right_1 + B.longest;
    } else {
        par.Right_0 = B.Right_0;
        par.Right_1 = B.Right_1;
    }

    par.longest = max(A.longest, B.longest);
    par.longest = max(par.longest, max(A.Right_0 + B.Left_0, A.Right_1 + B.Left_1));
    par.longest = max(par.longest, max(par.Left_0, par.Left_1));
    par.longest = max(par.longest, max(par.Right_0, par.Right_1));
}

void Modify(int id, int l, int r, int p) {
    if (l > p || r < p) return;
    if (l == r) {
        if (Seg[id].all_0) {
            Seg[id].all_1 = true;
            Seg[id].all_0 = false;
        } else {
            Seg[id].all_0 = true;
            Seg[id].all_1 = false;
        }

        return;
    }

    int mid = (l + r) >> 1;

    Modify(id*2+1, l, mid, p);
    Modify(id*2+2, mid+1, r, p);

    Merge(Seg[id], Seg[id*2+1], Seg[id*2+2]);
}

int Query_Root() {
    return Seg[0].longest;
}

string S;
int n, q;

void Build(int id, int l, int r) {
    if (l > r) return;
    if (l == r) {
        Seg[id].longest = 1;

        if (S[l-1] == '0') Seg[id].all_0 = true;
        else Seg[id].all_1 = true;

        return;
    }

    int mid = (l + r) >> 1;

    Build(id*2+1, l, mid);
    Build(id*2+2, mid+1, r);

    Merge(Seg[id], Seg[id*2+1], Seg[id*2+2]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> S; int n = S.size();
    Build(0, 1, n);

    cin >> q;
    while (q--) {
        int p; cin >> p;
        Modify(0, 1, n, p);

        cout << Query_Root() << ' ';
    }

    return 0;
}
