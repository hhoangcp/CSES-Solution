# Dynamic Range Sum Queries

**CSES ID:** 1648  
**Full statement:** https://cses.fi/problemset/task/1648  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

You maintain an array under point updates and range sum queries. Updates assign a single position a new value; queries ask for the total of values across a contiguous interval.

## Input
First line gives $n$ and $q$. Second line lists the $n$ array values. The following $q$ lines are either "$1$ $k$ $u$" (assign position $k$) or "$2$ $a$ $b$" (range sum query).

## Output
Print the answer to each type-2 query.

## Constraints
- $1 \le n,q \le 2 \cdot 10^5$
- $1 \le x_i, u \le 10^9$
- $1 \le k \le n$
- $1 \le a \le b \le n$
