# Transfer Speeds Sum

**CSES ID:** 3111  
**Full statement:** https://cses.fi/problemset/task/3111  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

A computer network forms a tree on $n$ computers with $n-1$ connections, each carrying a transfer speed. Define $d(a,b)$ as the minimum speed along the unique path between $a$ and $b$. Compute the sum of $d(a,b)$ over all unordered pairs $\{a,b\}$.

## Input
First line: $n$. Then $n-1$ lines, each with $a, b, x$ (an edge with transfer speed $x$).

## Output
Print one integer: the sum of transfer speeds over all unordered pairs.

## Constraints
- $1 \le n \le 2 \cdot 10^5$
- $1 \le x \le 10^6$
