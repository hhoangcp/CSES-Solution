# Xor Pyramid Diagonal

**CSES ID:** 3194  
**Full statement:** https://cses.fi/problemset/task/3194  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

A xor pyramid has a bottom row of numbers, and each higher entry is the xor of the two entries directly below it. Given the bottom row, output the leftmost (first) value of every row from bottom to top.

## Input
First line: integer $n$. Second line: $n$ integers $a_1,\dots,a_n$ (the bottom row).

## Output
Print $n$ integers: the leftmost values of the rows from bottom to top.

## Constraints
- $1 \le n \le 2 \cdot 10^5$
- $1 \le a_i \le 10^9$
