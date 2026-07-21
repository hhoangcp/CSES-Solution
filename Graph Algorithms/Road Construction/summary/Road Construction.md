# Road Construction

**CSES ID:** 1676  
**Full statement:** https://cses.fi/problemset/task/1676  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Starting with $n$ isolated cities, $m$ roads are added one per day. After each addition, report the number of connected components and the size of the largest component.

## Input
$n$ and $m$, then $m$ lines each giving an undirected edge $a, b$ added that day.

## Output
$m$ lines, each with the component count and the largest component size.

## Constraints
- $1 \le n \le 10^5$
- $1 \le m \le 2 \cdot 10^5$
- $1 \le a,b \le n$
