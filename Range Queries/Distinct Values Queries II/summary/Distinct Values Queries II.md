# Distinct Values Queries II

**CSES ID:** 3356  
**Full statement:** https://cses.fi/problemset/task/3356  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

You maintain an array under two operations: point updates and range queries that ask whether every value in a given interval is distinct. You must answer each range query as YES or NO.

## Input
First line gives $n$ and $q$. Second line lists the $n$ initial values. The following $q$ lines are either "$1$ $k$ $u$" (set position $k$ to $u$) or "$2$ $a$ $b$" (check range $[a,b]$).

## Output
For each type-2 query print `YES` if all values in the range are distinct, otherwise `NO`.

## Constraints
- $1 \le n, q \le 2 \cdot 10^5$
- $1 \le x_i, u \le 10^9$
- $1 \le k \le n$
- $1 \le a \le b \le n$
