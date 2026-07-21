# One Bit Positions

**CSES ID:** 2112  
**Full statement:** https://cses.fi/problemset/task/2112  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Given a binary string of length $n$, for every distance $k$ from $1$ to $n-1$, count the number of position pairs $(i,j)$ with $i-j=k$ where both positions hold a `1` bit.

## Input
A single line containing a binary string of characters `0` and `1`.

## Output
Print $n-1$ integers, the counts for $k=1,\ldots,n-1$.

## Constraints
- $2 \le n \le 2 \cdot 10^5$
