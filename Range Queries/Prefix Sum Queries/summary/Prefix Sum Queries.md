# Prefix Sum Queries

**CSES ID:** 2166  
**Full statement:** https://cses.fi/problemset/task/2166  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

You maintain an array of (possibly negative) integers under point updates. Each query on $[a,b]$ asks for the largest prefix-sum of the subarray $x_a,\dots,x_b$, where the empty prefix (sum 0) is allowed.

## Input
First line gives $n$ and $q$. Second line lists the array values. The following $q$ lines are either "$1$ $k$ $u$" (assign position $k$) or "$2$ $a$ $b$" (max prefix sum in $[a,b]$).

## Output
Print the answer to each type-2 query.

## Constraints
- $1 \le n,q \le 2 \cdot 10^5$
- $-10^9 \le x_i, u \le 10^9$
- $1 \le k \le n$
- $1 \le a \le b \le n$
