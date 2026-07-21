# Subarray Sum Constraints

**CSES ID:** 3294  
**Full statement:** https://cses.fi/problemset/task/3294  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Construct an array $x_1,\ldots,x_n$ of integers satisfying $m$ constraints of the form $\sum_{i=l}^{r} x_i = s$, or report that none exists.

## Input
Integers $n$ and $m$, then $m$ lines of $(l,r,s)$ constraints.

## Output
Print `YES` and any valid array with $|x_i| \le 10^{15}$, or just `NO`.

## Constraints
- $1 \le n \le 5000$
- $0 \le m \le 2 \cdot 10^5$
- $1 \le l \le r \le n$
- $-10^9 \le s \le 10^9$
