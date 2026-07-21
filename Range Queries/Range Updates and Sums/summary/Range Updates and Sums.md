# Range Updates and Sums

**CSES ID:** 1735  
**Full statement:** https://cses.fi/problemset/task/1735  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

You maintain an array under three operations: add a constant to every element in a range, assign a constant to every element in a range, and query the sum of a range.

## Input
First line gives $n$ and $q$. Second line lists the initial array. The following $q$ lines are "1 $a$ $b$ $x$" (range add), "2 $a$ $b$ $x$" (range assign), or "3 $a$ $b$" (range sum).

## Output
Print the answer to each sum query.

## Constraints
- $1 \le n, q \le 2 \cdot 10^5$
- $1 \le t_i, x \le 10^6$
- $1 \le a \le b \le n$
