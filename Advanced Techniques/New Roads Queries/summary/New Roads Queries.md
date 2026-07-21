# New Roads Queries

**CSES ID:** 2101  
**Full statement:** https://cses.fi/problemset/task/2101  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Byteland has $n$ cities and no roads initially; exactly one road is added each day for $m$ days. Answer $q$ queries asking the earliest day number after which cities $a$ and $b$ become connected (or $-1$ if never).

## Input
First line: $n,m,q$. Then $m$ lines giving roads in build order, each with two integers $a,b$. Then $q$ query lines, each with two integers $a,b$.

## Output
For each query, print the day number, or $-1$ if the cities are never connected.

## Constraints
- $1 \le n,m,q \le 2 \cdot 10^5$
- $1 \le a,b \le n$
