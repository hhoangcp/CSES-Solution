# Xor Pyramid Row

**CSES ID:** 3195  
**Full statement:** https://cses.fi/problemset/task/3195  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

In a xor pyramid each entry is the xor of the two entries below it. Given the bottom row of size $n$ and a target level $k$ (counted from the top), output all $k$ values that lie on that level.

## Input
First line: integers $n$ and $k$. Second line: $n$ integers $a_1,\dots,a_n$ (the bottom row).

## Output
Print $k$ integers: the entries on the $k$-th row from the top.

## Constraints
- $1 \le k \le n \le 2 \cdot 10^5$
- $1 \le a_i \le 10^9$
