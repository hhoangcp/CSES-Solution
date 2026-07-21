# Xor Pyramid Peak

**CSES ID:** 2419  
**Full statement:** https://cses.fi/problemset/task/2419  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

In a xor pyramid each entry is the xor of the two entries below it. Given the bottom row, determine the single value at the apex.

## Input
First line: integer $n$. Second line: $n$ integers $a_1,\dots,a_n$ (the bottom row).

## Output
One integer: the topmost value of the pyramid.

## Constraints
- $1 \le n \le 2 \cdot 10^5$
- $1 \le a_i \le 10^9$
