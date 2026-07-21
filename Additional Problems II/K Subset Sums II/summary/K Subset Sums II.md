# K Subset Sums II

**CSES ID:** 3109  
**Full statement:** https://cses.fi/problemset/task/3109  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Given $n$ integers, consider only the $\binom{n}{m}$ subsets of exactly $m$ elements and their sums. Output the $k$ smallest such sums in increasing order.

## Input
First line: $n$, $m$ and $k$. Next line: $n$ integers $x_1,\dots,x_n$.

## Output
Print $k$ integers: the $k$ smallest $m$-element subset sums in increasing order.

## Constraints
- $1 \le m < n \le 2 \cdot 10^5$
- $1 \le k \le \min\left(\binom{n}{m}, 2 \cdot 10^5\right)$
- $-10^9 \le x_i \le 10^9$
