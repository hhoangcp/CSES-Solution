# Monotone Subsequences

**CSES ID:** 2215  
**Full statement:** https://cses.fi/problemset/task/2215  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

For each test, build a permutation of $1,2,\dots,n$ whose longest monotone (increasing or decreasing) subsequence has length exactly $k$. A monotone subsequence is one that is either entirely nondecreasing or entirely nonincreasing.

## Input
First line: integer $t$. Then $t$ lines, each with two integers $n$ and $k$.

## Output
For each test print a valid permutation, or `IMPOSSIBLE` if none exists.

## Constraints
- $1 \le t \le 1000$
- $1 \le k \le n \le 100$
