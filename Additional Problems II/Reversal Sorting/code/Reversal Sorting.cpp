
#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <chrono>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef struct TNode {
    TNode *L, *R, *Par;
    int pri, key;
    int siz;
    bool rev;
} *node;

node Pos[200006];

node New_node(int key) {
    node P = new TNode();

    P->L = P->R = NULL;
    P->key = key; P->pri = rng();
    P->siz = 1;
    P->rev = false;
    Pos[key] = P;

    return P;
}

int Get_size(node P) {
    if (P == NULL) return 0;
    return P->siz;
}

void Update_node(node P) {
    if (P == NULL) return;
    P->siz = Get_size(P->L) + Get_size(P->R) + 1;
}

void Set_Par(node child, node par) {
    if (child == NULL) return;
    child->Par = par;
}

node Rotate_Left(node P) {
    node x = P->R, y = x->L;

    x->L = P; P->R = y;
    Set_Par(x, P->Par);
    Set_Par(P, x);
    Set_Par(y, P);

    Update_node(P);
    Update_node(x);

    return x;
}

node Rotate_Right(node P) {
    node x = P->L, y = x->R;

    x->R = P; P->L = y;
    Set_Par(x, P->Par);
    Set_Par(P, x);
    Set_Par(y, P);

    Update_node(P);
    Update_node(x);

    return x;
}

void Insert(node &P, int pos, int key) {
    if (P == NULL) {
        P = New_node(key);
        return;
    }

    if (Get_size(P->L) >= pos - 1) {
        Insert(P->L, pos, key);
        Set_Par(P->R, P);
        if (P->L->pri > P->pri) P = Rotate_Right(P);
    } else {
        Insert(P->R, pos - Get_size(P->L) - 1, key);
        Set_Par(P->R, P);
        if (P->R->pri > P->pri) P = Rotate_Left(P);
    }

    Update_node(P);
}

void Reverse(node P) {
    if (P == NULL) return;

    if (P->rev) {
        P->rev = false;
        swap(P->L, P->R);

        if (P->L != NULL) P->L->rev ^= true;
        if (P->R != NULL) P->R->rev ^= true;
    }
}

void Split(node P, node &T1, node &T2, int pos, bool one) {
    if (P == NULL) {
        T1 = T2 = NULL;
        return;
    }

    Reverse(P);

    if (pos <= Get_size(P->L)) {
        T2 = P;
        Split(P->L, T1, T2->L, pos, false);
        Set_Par(T2->L, T2);
    } else if (pos > Get_size(P->L) + 1) {
        T1 = P;
        Split(P->R, T1->R, T2, pos - Get_size(P->L) - 1, false);
        Set_Par(T1->R, T1);
    } else {
        T2 = P;
        T1 = P->L;
        Set_Par(T1, NULL);
        T2->L = NULL;
    }

    Update_node(T1);
    Update_node(T2);

    if (one) Set_Par(T2, NULL), Set_Par(T1, NULL);
}

int Find_by_order(node P, int pos) {
    if (P == NULL) return -1;

    Reverse(P);

    if (pos <= Get_size(P->L)) return Find_by_order(P->L, pos);
    if (pos > Get_size(P->L) + 1) return Find_by_order(P->R, pos - Get_size(P->L) - 1);

    return P->key;
}

int Find_pos(int x) {
    node cur = Pos[x];
    vector<node> Cur;

    while (cur != NULL) {
        Cur.push_back(cur);
        cur = cur->Par;
    }

    while (!Cur.empty()) {
        node P = Cur.back(); Cur.pop_back();
        Reverse(P);
    }

    cur = Pos[x];
    int pos = Get_size(cur->L) + 1;

    while (cur != NULL) {
        node Par = cur->Par;
        if (Par == NULL) break;

        if (Par->R == cur) pos += Get_size(Par->L) + 1;
        cur = Par;
    }

    return pos;
}

void Merge(node &P, node T1, node T2, bool one) {
    Reverse(T1);
    Reverse(T2);

    if (T1 == NULL) P = T2;
    else if (T2 == NULL) P = T1;
    else {
        if (T1->pri > T2->pri) {
            P = T1;
            Merge(P->R, T1->R, T2, false);
            Set_Par(P->R, P);
        } else {
            P = T2;
            Merge(P->L, T1, T2->L, false);
            Set_Par(P->L, P);
        }
    }

    Update_node(P);
    if (one) Set_Par(P, NULL);
}

int n;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n; node root = NULL;

    for(int i = 1; i <= n; ++i) {
        int a; cin >> a;
        Insert(root, i, a);
    }

    vector<pair<int, int> > Reverse_Sorting;

    for(int i = 1; i <= n; ++i) {
        int a = Find_by_order(root, i);
        if (a == i) continue;

        int pos = Find_pos(i);
        Reverse_Sorting.push_back({i, pos});

        node T1, T2, T3;
        Split(root, T2, T3, pos+1, true);
        Split(T2, T1, T2, i, true);

        T2->rev ^= true;

        Merge(root, T1, T2, true);
        Merge(root, root, T3, true);
    }

    cout << Reverse_Sorting.size() << '\n';
    for(pair<int, int> p: Reverse_Sorting) cout << p.first << ' ' << p.second << '\n';

    return 0;
}
