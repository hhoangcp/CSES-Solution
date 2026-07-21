# Range Update Queries

**CSES ID:** 1651  
**Full statement:** https://cses.fi/problemset/task/1651  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

You maintain an array under range-add updates (add $u$ to every element in $[a,b]$) and point queries (read the value at position $k$).

## Input
First line gives $n$ and $q$. Second line lists the array values. The following $q$ lines are either "$1$ $a$ $b$ $u$" (range add) or "$2$ $k$" (read position $k$).

## Output
Print the answer to each type-2 query.

## Constraints
- $1 \le n,q \le 2 \cdot 10^5$
- $1 \le x_i, u \le 10^9$
- $1 \le k \le n$
- $1 \le a \le b \le n$
