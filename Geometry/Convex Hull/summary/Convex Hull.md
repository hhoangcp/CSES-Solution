# Convex Hull

**CSES ID:** 2195  
**Full statement:** https://cses.fi/problemset/task/2195  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Given $n$ distinct points in the plane, you must find all points that lie on the boundary of their convex hull. The hull has positive area by assumption.

## Input
First an integer $n$, then $n$ lines each with two integers $x$ and $y$ giving a point's coordinates.

## Output
First print the count $k$ of hull points, then $k$ lines listing those points in any order.

## Constraints
- $3 \le n \le 2 \cdot 10^5$
- $-10^9 \le x, y \le 10^9$
