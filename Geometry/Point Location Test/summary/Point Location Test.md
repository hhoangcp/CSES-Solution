# Point Location Test

**CSES ID:** 2189  
**Full statement:** https://cses.fi/problemset/task/2189  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

For each of $t$ tests you are given a directed line through $p_1$ and $p_2$ and a query point $p_3$. Classify $p_3$ as lying to the left, to the right, or exactly on the line when viewed from $p_1$ toward $p_2$.

## Input
First an integer $t$, then $t$ lines each with six integers $x_1, y_1, x_2, y_2, x_3, y_3$.

## Output
For each test print "LEFT", "RIGHT", or "TOUCH".

## Constraints
- $1 \le t \le 10^5$
- $-10^9 \le x_1, y_1, x_2, y_2, x_3, y_3 \le 10^9$
- $x_1 \neq x_2$ or $y_1 \neq y_2$
