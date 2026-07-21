# Lines and Queries I

**CSES ID:** 3429  
**Full statement:** https://cses.fi/problemset/task/3429  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

You maintain a dynamic set of lines of the form $y = ax + b$ and must process two query types: insert a new line, and at a given position $x$ report the maximum value attained by any inserted line.

## Input
First an integer $n$, then $n$ lines each either "1 $a$ $b$" (insert line $ax+b$) or "2 $x$" (query at $x$). The first query is of type 1.

## Output
For each type-2 query print the maximum value at that position.

## Constraints
- $1 \le n \le 2 \cdot 10^5$
- $-10^9 \le a, b \le 10^9$
- $0 \le x \le 10^5$
