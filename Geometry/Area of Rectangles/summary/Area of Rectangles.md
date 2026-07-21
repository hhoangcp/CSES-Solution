# Area of Rectangles

**CSES ID:** 1741  
**Full statement:** https://cses.fi/problemset/task/1741  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

You are given $n$ axis-aligned rectangles, each defined by its lower-left and upper-right corners. The task is to compute the area of their union, where overlapping regions are counted only once.

## Input
First an integer $n$, then $n$ lines each with four integers $x_1, y_1, x_2, y_2$ giving the bottom-left and top-right corners of a rectangle.

## Output
Print the total area covered by the union of all rectangles.

## Constraints
- $1 \le n \le 10^5$
- $-10^6 \le x_1 < x_2 \le 10^6$
- $-10^6 \le y_1 < y_2 \le 10^6$
