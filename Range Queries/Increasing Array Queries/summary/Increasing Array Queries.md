# Increasing Array Queries

**CSES ID:** 2416  
**Full statement:** https://cses.fi/problemset/task/2416  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

You may repeatedly increase any array element by 1 (one operation per increment). For each query on a subarray $[a,b]$ you must report the minimum number of such increments needed to make that subarray non-decreasing (each element $\ge$ the previous one).

## Input
First line gives $n$ and $q$. Second line lists the array values. The following $q$ lines each give endpoints $a$ and $b$ of a subarray.

## Output
For each query print the minimum number of increment operations required.

## Constraints
- $1 \le n,q \le 2\cdot10^5$
- $1 \le x_i \le 10^9$
- $1 \le a \le b \le n$
