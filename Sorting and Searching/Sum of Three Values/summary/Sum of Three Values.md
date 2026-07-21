# Sum of Three Values

**CSES ID:** 1641  
**Full statement:** https://cses.fi/problemset/task/1641  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Given an array of $n$ integers and a target $x$, find three distinct positions whose values sum to $x$.

## Input
First line: integers $n$ and $x$. Second line: $n$ integers $a_1,\ldots,a_n$.

## Output
Print three positions (1-indexed) of the chosen values, or `IMPOSSIBLE` if none exist. Any valid solution is accepted.

## Constraints
- $1 \le n \le 5000$
- $1 \le x, a_i \le 10^9$
