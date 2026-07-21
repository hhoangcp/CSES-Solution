# Lines and Queries II

**CSES ID:** 3430  
**Full statement:** https://cses.fi/problemset/task/3430  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Like the previous task you maintain lines $y = ax+b$ and answer max-at-position queries, but now each line is only active over a specified interval $[l,r]$. A type-2 query reports the maximum among lines active at that $x$, or `NO` if none is active.

## Input
First an integer $n$, then $n$ lines each either "1 $a$ $b$ $l$ $r$" (insert a line active on $[l,r]$) or "2 $x$" (query at $x$).

## Output
For each type-2 query print the maximum value, or `NO` if no line is active there.

## Constraints
- $1 \le n \le 2 \cdot 10^5$
- $-10^9 \le a, b \le 10^9$
- $0 \le x \le 10^5$
- $0 \le l \le r \le 10^5$
