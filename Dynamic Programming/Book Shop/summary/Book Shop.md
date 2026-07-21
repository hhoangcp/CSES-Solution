# Book Shop

**CSES ID:** 1158  
**Full statement:** https://cses.fi/problemset/task/1158  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

A shop offers $n$ books, each with a price and a page count. With a budget of at most $x$ and each book usable once, choose a subset maximizing total pages without exceeding the budget.

## Input
Integers $n$ and $x$, then $n$ prices $h_i$, then $n$ page counts $s_i$.

## Output
The maximum attainable total number of pages.

## Constraints
- $1 \le n \le 1000$
- $1 \le x \le 10^5$
- $1 \le h_i, s_i \le 1000$
