# Intersection Points

**CSES ID:** 1740  
**Full statement:** https://cses.fi/problemset/task/1740  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

You are given $n$ line segments that are each either horizontal or vertical. Count how many distinct intersection points exist among them. By assumption parallel segments never overlap and no endpoint itself is an intersection point.

## Input
First an integer $n$, then $n$ lines each with four integers $x_1, y_1, x_2, y_2$ describing one segment's endpoints.

## Output
Print the total number of intersection points.

## Constraints
- $1 \le n \le 10^5$
- $-10^6 \le x_1 \le x_2 \le 10^6$
- $-10^6 \le y_1 \le y_2 \le 10^6$
- $(x_1,y_1) \neq (x_2,y_2)$
