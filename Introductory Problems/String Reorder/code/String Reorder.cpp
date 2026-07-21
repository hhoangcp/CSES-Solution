
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int cnt[26], n;
char S[1000006];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    scanf("%s", S+1); n = strlen(S+1);
    for(int i = 1; i <= n; ++i) {
        int c = S[i] - 'A';
        ++cnt[c];
    }

    for(int i = 0; i < 26; ++i)
    if (cnt[i] * 2 > n + 1) return cout << -1, 0;

    int last = -1;
    for(; n > 0; --n) {
        int c = -1;

        for(int i = 0; i < 26; ++i)
        if (i != last && cnt[i] > 0 && cnt[i] * 2 - n == 1) {
            c = i;
            break;
        }

        if (c == -1) {
            for(int i = 0; i < 26; ++i)
            if (i != last && cnt[i] > 0 && cnt[i] * 2 - n < 1) {
                c = i;
                break;
            }
        }

        if (c == -1) return cout << -1, 0;

        --cnt[c];
        cout << char(c + 'A');
        last = c;
    }

    return 0;
}
