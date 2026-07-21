
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

bool t[100006];
int Num[100006];

void Bucket(int a[], int n, int K, bool End) {
    for(int i=0; i<K; ++i) Num[i] = 0;
    for(int i=0; i<n; ++i) ++Num[a[i]];

    if (End)
        for(int i=1; i < K; ++i) Num[i] += Num[i-1];
    else
        for(int i=0, sum = 0; i < K; ++i) {
            sum += Num[i];
            Num[i] = sum - Num[i];
        }
}

void Plus_to_Minus(int a[], int sa[], int n, int K) {
    Bucket(a, n, K, false);
    sa[Num[a[n-1]]++] = n-1;

    for(int i=0; i < n - 1; ++i) {
        int j = sa[i] - 1;
        if (j >= 0 && !t[j]) sa[Num[a[j]]++] = j;
    }
}

void Minus_to_Plus(int a[], int sa[], int n, int K) {
    Bucket(a, n, K, true);
    for(int i=n-1; i>=0; --i) {
        int j = sa[i] - 1;
        if (j >= 0 && t[j]) sa[--Num[a[j]]] = j;
    }
}

void Suffix_Array(int a[], int sa[], int n, int K) {
    t[n - 1] = false;
    for(int i = n - 2; i >= 0; --i)
        t[i] = a[i] < a[i+1] || (a[i] == a[i+1] && t[i+1]);

    bool minor = 2 * count(t, t+n, false) > n;
    Bucket(a, n, K, minor);
    for(int i=0; i<n; ++i) sa[i] = -1;

    if (minor) {
        for(int i=0; i<n; ++i)
        if (t[i]) sa[--Num[a[i]]] = i;

        Plus_to_Minus(a, sa, n, K);
        Minus_to_Plus(a, sa, n, K);
    } else {
        for(int i=0; i<n; ++i)
        if (!t[i]) sa[Num[a[i]]++] = i;

        Minus_to_Plus(a, sa, n, K);
        Plus_to_Minus(a, sa, n, K);
    }

    int last = -1, name = 0, cnt = count(t, t+n, minor), *sa2, *pi;
    if (minor) sa2 = sa, pi = sa + n - cnt;
    else sa2 = sa + n - cnt, pi = sa;

    for(int i = 0; i < n; ++i) Num[i] = -1;
    for(int i = 0; i < n; ++i)
    if (sa[i] >= 0 && minor == t[sa[i]]) {
        bool diff = last == -1;
        int p = sa[i];

        if (!diff) {
            for(int j = 0; j < n; ++j)
            if (last + j >= n || p + j >= n || a[last + j] != a[p + j] || t[last + j] != t[p + j]) {
                diff = true;
                break;
            } else if (j > 0 && (minor == t[last+j] || minor == t[p+j])) break;
        }

        if (diff) {
            ++name;
            last = p;
        }

        Num[p] = name - 1;
    }

    cnt = 0;
    for(int i = 0; i < n; ++i)
    if (Num[i] >= 0) pi[cnt++] = Num[i];

    if (name < cnt) Suffix_Array(pi, sa2, cnt, name);
    else for(int i=0; i < cnt; ++i) sa2[pi[i]] = i;

    for(int i = cnt - 1; i >= 0; --i)
        t[i] = a[i] < a[i+1] || (a[i] == a[i+1] && t[i+1]);

    cnt = 0;
    Bucket(a, n, K, minor);

    for(int i=0; i < n; ++i)
    if (minor == t[i]) pi[cnt++] = i;

    if (minor) {
        for(int i = 0; i < cnt; ++i) sa[i] = pi[sa2[i]];
        for(int i = cnt - 1; i >= 0; --i) {
            int j = sa[i]; sa[i] = -1;
            sa[--Num[a[j]]] = j;
        }

        Plus_to_Minus(a, sa, n, K);
    } else {
        for(int i = 0; i < cnt; ++i) sa[n-cnt+i] = pi[sa2[i]];
        for(int i = 0; i < cnt; ++i) {
            int j = sa[n-cnt+i]; sa[n-cnt+i] = -1;
            sa[Num[a[j]]++] = j;
        }

        Minus_to_Plus(a, sa, n, K);
    }
}

int Rank[100006], res = -1, pos = 0;

void cal_LCP(int a[], int sa[], int n, int lcp[]) {
    for(int i = 0; i < n; ++i) Rank[sa[i]] = i;

    for(int i = 0, h = 0; i < n; ++i) {
        if (Rank[i] == 0) {
            h = 0;
            continue;
        }

        for(int j = sa[Rank[i]-1]; i + h < n && j + h < n && a[i+h] == a[j+h]; ++h);

        lcp[Rank[i]] = h;

        if (res < h) {
            res = h;
            pos = i;
        }

        if (h > 0) --h;
    }
}

int n, q, a[100006], sa[100006], lcp[100006];
char S[100006], P[100006];

int main() {
    scanf("%s", S); n = strlen(S);
    for(int i = 0; i < n; ++i) a[i] = (int) S[i];

    Suffix_Array(a, sa, n, 256);
    cal_LCP(a, sa, n, lcp);

    if (res <= 0) cout << -1;
    else for(int i = pos; i < pos + res; ++i) putchar(S[i]);

    return 0;
}
