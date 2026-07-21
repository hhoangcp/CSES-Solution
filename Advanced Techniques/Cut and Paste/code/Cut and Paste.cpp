
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef struct TNode {
    TNode *L, *R;
    int pri, key;
    int siz;
} *node;

node New_node(int key) {
    node P = new TNode();

    P->L = P->R = NULL;
    P->key = key; P->pri = rng();
    P->siz = 1;

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

node Rotate_Left(node P) {
    node x = P->R, y = x->L;

    x->L = P; P->R = y;

    Update_node(P);
    Update_node(x);

    return x;
}

node Rotate_Right(node P) {
    node x = P->L, y = x->R;

    x->R = P; P->L = y;

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
        if (P->L->pri > P->pri) P = Rotate_Right(P);
    } else {
        Insert(P->R, pos - Get_size(P->L) - 1, key);
        if (P->R->pri > P->pri) P = Rotate_Left(P);
    }

    Update_node(P);
}

void Split(node P, node &T1, node &T2, int pos) {
    if (P == NULL) {
        T1 = T2 = NULL;
        return;
    }

    if (pos <= Get_size(P->L)) {
        T2 = P;
        Split(P->L, T1, T2->L, pos);
    } else if (pos > Get_size(P->L) + 1) {
        T1 = P;
        Split(P->R, T1->R, T2, pos - Get_size(P->L) - 1);
    } else {
        T2 = P;
        T1 = P->L;
        T2->L = NULL;
    }

    Update_node(T1);
    Update_node(T2);
}

void Merge(node &P, node T1, node T2) {
    if (T1 == NULL) P = T2;
    else if (T2 == NULL) P = T1;
    else {
        if (T1->pri > T2->pri) {
            P = T1;
            Merge(P->R, T1->R, T2);
        } else {
            P = T2;
            Merge(P->L, T1, T2->L);
        }
    }

    Update_node(P);
}

string S;
int n, q;

void DFS(node P) {
    if (P == NULL) return;

    DFS(P->L);
    cout << S[P->key];
    DFS(P->R);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> q >> S; node root = NULL;
    for(int i = 0; i < n; ++i) Insert(root, i+1, i);

    while (q--) {
        int u, v; cin >> u >> v;

        node T1, T2, T3;
        Split(root, T2, T3, v + 1);
        Split(T2, T1, T2, u);

        Merge(root, T1, T3);
        Merge(root, root, T2);
    }

    DFS(root);

    return 0;
}
