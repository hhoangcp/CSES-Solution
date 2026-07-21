# Maximum Manhattan Distances

**CSES ID:** 3410  
**Full statement:** https://cses.fi/problemset/task/3410  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Starting from an empty set, points are added one at a time. After each insertion you must report the largest Manhattan distance between any two points currently in the set.

## Input
First an integer $n$, then $n$ lines each with two integers $x$ and $y$ describing a distinct point.

## Output
After each addition print the current maximum Manhattan distance between two points.

## Constraints
- $1 \le n \le 2 \cdot 10^5$
- $-10^9 \le x, y \le 10^9$
