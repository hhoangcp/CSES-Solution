# Sliding Window Advertisement

**CSES ID:** 3227  
**Full statement:** https://cses.fi/problemset/task/3227  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

A fence is built from $n$ unit-width vertical boards with given heights. For each consecutive block of $k$ boards, you must determine the largest rectangle (advertisement) that fits fully inside that block, using the board heights as upper bounds. Output one value per window.

## Input
First line: $n$ and $k$. Second line: the $n$ board heights $x_1,\dots,x_n$.

## Output
Print $n-k+1$ integers, the maximum advertisement area in each window.

## Constraints
- $1 \le k \le n \le 2 \cdot 10^5$
- $1 \le x_i \le 10^9$
