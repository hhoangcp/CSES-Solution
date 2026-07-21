# Graph Coloring

**CSES ID:** 3308  
**Full statement:** https://cses.fi/problemset/task/3308  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Color the vertices of a simple graph using the minimum number of colors so that no two adjacent vertices share a color (the chromatic number).

## Input
First line: $n$ and $m$. Then $m$ lines each with an edge between two distinct nodes $a,b$.

## Output
Print the minimum number of colors $k$, then $n$ integers $c_1,\dots,c_n$ with $1 \le c_i \le k$; any valid coloring is accepted.

## Constraints
- $1 \le n \le 16$
- $0 \le m \le \frac{n(n-1)}{2}$
