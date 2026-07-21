# Line Segment Intersection

**CSES ID:** 2190  
**Full statement:** https://cses.fi/problemset/task/2190  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

For each of $t$ tests you are given two segments in the plane and must decide whether they share at least one point, including endpoints and the degenerate collinear overlap case.

## Input
First an integer $t$, then $t$ lines each with eight integers $x_1, y_1, x_2, y_2, x_3, y_3, x_4, y_4$ describing the two segments.

## Output
For each test print "YES" if the segments intersect and "NO" otherwise.

## Constraints
- $1 \le t \le 10^5$
- $-10^9 \le x_1, y_1, x_2, y_2, x_3, y_3, x_4, y_4 \le 10^9$
- $(x_1,y_1) \neq (x_2,y_2)$
- $(x_3,y_3) \neq (x_4,y_4)$
