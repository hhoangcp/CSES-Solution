# Permutation Order

**CSES ID:** 3397  
**Full statement:** https://cses.fi/problemset/task/3397  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Let $p(n,k)$ be the $k$-th permutation of $1 \dots n$ in lexicographic order. Process two query types: given $n$ and $k$, output $p(n,k)$; or given $n$ and a permutation, output its lexicographic rank $k$.

## Input
The first line is $t$. Each test is either `1 n k` or `2 n` followed by the permutation.

## Output
For type 1 print the permutation elements separated by spaces; for type 2 print the rank $k$.

## Constraints
- $1 \le t \le 1000$
- $1 \le n \le 20$
- $1 \le k \le n!$
