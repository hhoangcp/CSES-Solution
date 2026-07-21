# And Subset Count

**CSES ID:** 3141  
**Full statement:** https://cses.fi/problemset/task/3141  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Given an array of integers, count for every $k$ from $0$ to $n$ how many non-empty subsets have bitwise AND exactly equal to $k$.

## Input
First line: integer $n$. Second line: $n$ integers $a_1,\dots,a_n$.

## Output
Print $n+1$ integers: the counts for $k = 0, 1, \dots, n$, each modulo $10^9+7$.

## Constraints
- $1 \le n \le 2 \cdot 10^5$
- $0 \le a_i \le n$
