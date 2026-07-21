# Hotel Queries

**CSES ID:** 1143  
**Full statement:** https://cses.fi/problemset/task/1143  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

There are $n$ hotels each with a known count of free rooms. Tourist groups arrive one by one, each requesting some number of rooms; you must assign each group to the leftmost hotel that still has enough free rooms and decrement that hotel's count. If none suffices you output 0.

## Input
First line gives $n$ (hotels) and $m$ (groups). Second line lists the free-room counts $h_1,\dots,h_n$. Third line lists the requested room counts $r_1,\dots,r_m$.

## Output
For each group, print the assigned hotel index, or 0 if no hotel fits.

## Constraints
- $1 \le n,m \le 2 \cdot 10^5$
- $1 \le h_i \le 10^9$
- $1 \le r_i \le 10^9$
