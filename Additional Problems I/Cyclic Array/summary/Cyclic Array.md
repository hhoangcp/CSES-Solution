# Cyclic Array

**CSES ID:** 1191  
**Full statement:** https://cses.fi/problemset/task/1191  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

You are given a circular array of $n$ positive values. Partition it into the fewest contiguous segments (wrapping allowed) such that every segment's sum is at most $k$. It is guaranteed that no single element exceeds $k$.

## Input
Integers $n$ and $k$, then $n$ array values.

## Output
Print the minimum number of segments.

## Constraints
- $1 \le n \le 2 \cdot 10^5$
- $1 \le x_i \le 10^9$
- $1 \le k \le 10^{18}$
