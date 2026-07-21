# Range Queries and Copies

**CSES ID:** 1737  
**Full statement:** https://cses.fi/problemset/task/1737  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

You maintain a list of arrays (initially one) and must process three operations: assign a value at a position of a chosen array, query the sum over a range of a chosen array, and append a copy of an existing array to the list.

## Input
First line gives array size $n$ and query count $q$. Second line lists the initial array. The $q$ query lines are "1 $k$ $a$ $x$" (set), "2 $k$ $a$ $b$" (sum), or "3 $k$" (copy).

## Output
Print the answer to each sum query.

## Constraints
- $1 \le n, q \le 2 \cdot 10^5$
- $1 \le t_i, x \le 10^9$
- $1 \le a \le b \le n$
