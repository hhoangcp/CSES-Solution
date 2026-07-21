# Planets Queries II

**CSES ID:** 1160  
**Full statement:** https://cses.fi/problemset/task/1160  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Each of $n$ planets teleports to $t_i$. Answer $q$ queries: from planet $a$, the minimum number of teleportations to first reach planet $b$, or $-1$ if unreachable.

## Input
$n$ and $q$, then $n$ targets $t_i$, then $q$ lines each with $a, b$.

## Output
The minimum teleportation count per query, or $-1$.

## Constraints
- $1 \le n, q \le 2 \cdot 10^5$
- $1 \le a,b \le n$
