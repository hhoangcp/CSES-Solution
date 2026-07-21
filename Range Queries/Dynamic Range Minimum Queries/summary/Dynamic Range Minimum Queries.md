# Dynamic Range Minimum Queries

**CSES ID:** 1649  
**Full statement:** https://cses.fi/problemset/task/1649  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

You maintain an array under point updates and range minimum queries. Each update sets one position to a new value; each query asks for the smallest value within a contiguous range.

## Input
First line gives $n$ and $q$. Second line lists the $n$ array values. The following $q$ lines are either "$1$ $k$ $u$" (assign position $k$) or "$2$ $a$ $b$" (range minimum query).

## Output
Print the answer to each type-2 query.

## Constraints
- $1 \le n,q \le 2 \cdot 10^5$
- $1 \le x_i, u \le 10^9$
- $1 \le k \le n$
- $1 \le a \le b \le n$
