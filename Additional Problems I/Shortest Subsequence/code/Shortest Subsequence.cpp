
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

char S[1000006];

int main() {
    scanf("%s", S+1); int n = strlen(S+1);

    bool A = false, T = false, G = false, C = false;
    for(int i = 1; i <= n;) {
        while (i <= n && !(A && T && G && C)) {
            if (S[i] == 'A') A = true;
            if (S[i] == 'T') T = true;
            if (S[i] == 'G') G = true;
            if (S[i] == 'C') C = true;
            ++i;
        }

        if (A && T && G && C) {
            putchar(S[i-1]);
            A = T = G = C = false;
        }
    }

    if (!A) putchar('A');
    else if (!T) putchar('T');
    else if (!G) putchar('G');
    else if (!C) putchar('C');

    return 0;
}
