# Line Segments Trace I

**CSES ID:** 3427  
**Full statement:** https://cses.fi/problemset/task/3427  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

You are given $n$ segments that all span the horizontal range from $x=0$ to $x=m$ with integer slope, each joining $(0,y_1)$ and $(m,y_2)$. For each integer $x \in [0,m]$ you must report the maximum $y$ value reached by any segment at that column.

## Input
First line has two integers $n$ and $m$, then $n$ lines each with two integers $y_1$ and $y_2$ describing a segment's endpoints.

## Output
Print $m+1$ integers: the maximum point for $x=0,1,\dots,m$.

## Constraints
- $1 \le n, m \le 10^5$
- $0 \le y_1, y_2 \le 10^9$
