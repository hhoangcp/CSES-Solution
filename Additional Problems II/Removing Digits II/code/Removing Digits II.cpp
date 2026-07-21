
#include <iostream>
#include <algorithm>
#include <map>
#define llong long long
#define Pair pair<llong, llong>

using namespace std;

map<Pair, Pair> dp;

Pair compute(Pair A) {
    if (A.second < 10) return {A.first || A.second, A.second - max(A.first, A.second)};
    if (dp.count(A)) return dp[A];

    llong power = 1;
    while (power <= A.second / 10) power *= 10;

    Pair tmp = compute({max(A.first, A.second / power), A.second % power});
    llong delta = tmp.first;
    tmp = compute({A.first, A.second / power * power + tmp.second});

    return dp[A] = {tmp.first + delta, tmp.second};
}

int main() {
    llong n; cin >> n;
    cout << compute({0, n}).first;

    return 0;
}
