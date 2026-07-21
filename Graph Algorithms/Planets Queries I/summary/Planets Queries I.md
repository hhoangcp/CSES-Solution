# Planets Queries I

**CSES ID:** 1750  
**Full statement:** https://cses.fi/problemset/task/1750  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Each of $n$ planets has a teleporter to planet $t_i$. Answer $q$ queries: starting at planet $x$ and taking $k$ teleportations, which planet do you land on?

## Input
$n$ and $q$, then $n$ targets $t_i$, then $q$ lines each with $x, k$.

## Output
One planet index per query.

## Constraints
- $1 \le n, q \le 2 \cdot 10^5$
- $1 \le t_i \le n$
- $1 \le x \le n$
- $0 \le k \le 10^9$
