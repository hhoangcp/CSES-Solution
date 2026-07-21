# Same Sum Subsets

**CSES ID:** 3425  
**Full statement:** https://cses.fi/problemset/task/3425  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Given a set of $n$ positive integers, choose two disjoint subsets with equal sum. Output both subsets (size then elements) or report impossibility.

## Input
First line: $n$. Second line: $n$ integers $x_1,\dots,x_n$.

## Output
For each subset, print its size then its elements; print any valid solution, or `IMPOSSIBLE` if none exists.

## Constraints
- $3 \le n \le 40$
- $\sum_{i=1}^{n} x_i \le 2^{n}-2$
