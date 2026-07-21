# Book Shop II

**CSES ID:** 1159  
**Full statement:** https://cses.fi/problemset/task/1159  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

A shop sells $n$ book types; for each type you know its price, page count and available copies. Spend at most $x$ total to maximize total pages, possibly buying multiple copies of a type.

## Input
First line: $n$ and $x$. Next three lines give the prices $h_i$, page counts $s_i$, and copy counts $k_i$ of the $n$ books.

## Output
One integer: the maximum total pages attainable.

## Constraints
- $1 \le n \le 100$
- $1 \le x \le 10^5$
- $1 \le h_i, s_i, k_i \le 1000$
