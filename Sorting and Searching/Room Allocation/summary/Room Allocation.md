# Room Allocation

**CSES ID:** 1164  
**Full statement:** https://cses.fi/problemset/task/1164  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

For $n$ customers with arrival and departure days, find the minimum number of rooms needed and an assignment of each customer to a room. Two customers may share a room only if the earlier one departs before the other arrives.

## Input
First line: integer $n$. Then $n$ lines, each with arrival $a$ and departure $b$.

## Output
Print the minimum number of rooms $k$, then a line with the room number (1 to $k$) assigned to each customer in input order.

## Constraints
- $1 \le n \le 2 \cdot 10^5$
- $1 \le a \le b \le 10^9$
