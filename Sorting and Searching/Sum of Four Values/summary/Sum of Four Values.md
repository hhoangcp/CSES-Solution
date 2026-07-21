# Sum of Four Values

**CSES ID:** 1642  
**Full statement:** https://cses.fi/problemset/task/1642  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Given an array of $n$ integers and a target $x$, find four distinct positions whose values sum to $x$.

## Input
First line: integers $n$ and $x$. Second line: $n$ integers $a_1,\ldots,a_n$.

## Output
Print four positions (1-indexed) of the chosen values, or `IMPOSSIBLE` if none exist. Any valid solution is accepted.

## Constraints
- $1 \le n \le 1000$
- $1 \le x, a_i \le 10^9$
