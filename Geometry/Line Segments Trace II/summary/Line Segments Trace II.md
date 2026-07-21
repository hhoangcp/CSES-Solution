# Line Segments Trace II

**CSES ID:** 3428  
**Full statement:** https://cses.fi/problemset/task/3428  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

You are given $n$ segments with integer endpoints and integer slope, each spanning some horizontal interval $[x_1, x_2] \subseteq [0,m]$. For every integer $x \in [0,m]$ you must report the maximum $y$ reached by any segment covering that column, or $-1$ if no segment covers it.

## Input
First line has two integers $n$ and $m$, then $n$ lines each with four integers $x_1, y_1, x_2, y_2$ describing a segment's endpoints.

## Output
Print $m+1$ integers: the maximum point for $x=0,1,\dots,m$, using $-1$ where no segment exists.

## Constraints
- $1 \le n, m \le 10^5$
- $0 \le x_1 < x_2 \le m$
- $0 \le y_1, y_2 \le 10^9$
