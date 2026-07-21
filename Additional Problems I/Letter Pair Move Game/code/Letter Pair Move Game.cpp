/// Greedy
 
#include <iostream>
#include <algorithm>
 
using namespace std;
 
int n;
char S[206], Ans[1006][206];
 
bool checking() {
    int Max = 0, Min = n + 1;
    for(int i = 1; i <= n; ++i)
    if (S[i] == 'A') Max = i;
    else if (S[i] == 'B' && Min == n + 1) Min = i;
 
    return Max <= Min;
}
 
void Print(int k) {
    cout << k << '\n';
    for(int i = 1; i <= k; ++i) puts(Ans[i] + 1);
    exit(0);
}
 
bool Move(int &p, int &dot) {
    int pivot = 0;
 
    for(int i = 1; i < dot - 1 && !pivot; ++i) {
        if (S[i] == 'B' && S[i+1] == 'A') pivot = i;
        if (S[i] == 'B' && S[i+1] == 'B') pivot = i;
    }
 
    for(int i = dot + 2; i < n && !pivot; ++i) {
        if (S[i] == 'A' && S[i+1] == 'B') pivot = i;
        if (S[i] == 'A' && S[i+1] == 'A') pivot = i;
    }
 
    if (!pivot) {
        for(int i = dot + 2; i < n && !pivot; ++i)
            if (S[i] == 'B' && S[i+1] == 'A') pivot = i;
 
        if (!pivot) return false;
        ++p; swap(S[pivot], S[dot]), swap(S[pivot + 1], S[dot + 1]);
        for(int i = 1; i <= n; ++i) Ans[p][i] = S[i];
        dot = pivot;
 
        pivot = 0;
        for(int i = 1; i < dot - 1 && !pivot; ++i)
            if (S[i] == 'B' && S[i+1] == 'B') pivot = i;
 
        for(int i = 1; i < dot - 1 && !pivot; ++i)
            if (S[i] == 'A' && S[i+1] == 'B') pivot = i;
 
        if (!pivot) return false;
        ++p; swap(S[pivot], S[dot]), swap(S[pivot + 1], S[dot + 1]);
        for(int i = 1; i <= n; ++i) Ans[p][i] = S[i];
 
        dot = pivot;
    } else {
        ++p; swap(S[pivot], S[dot]), swap(S[pivot + 1], S[dot + 1]);
        for(int i = 1; i <= n; ++i) Ans[p][i] = S[i];
 
        dot = pivot;
    }
 
    return pivot != 0;
}
 
int main() {
    scanf("%d%s", &n, S+1); n *= 2;
 
    int dot = 0;
    for(int i = 1; i < n; ++i)
    if (S[i] == '.' && S[i + 1] == '.') {
        dot = i;
        break;
    }

    if (dot == 0) {
        printf("-1\n");
        return 0;
    }
 
    int i;
    for(i = 0; i <= 5*n;) {
        if (checking()) Print(i);
        if (!Move(i, dot)) break;
    }
 
    if (checking() && i <= 5*n) Print(i);
    cout << -1;
 
    return 0;
}
