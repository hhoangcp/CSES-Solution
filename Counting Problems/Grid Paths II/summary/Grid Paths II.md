# Grid Paths II

**CSES ID:** 1078  
**Full statement:** https://cses.fi/problemset/task/1078  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

From the top-left corner $(1,1)$ of an $n \times n$ grid, move to the bottom-right corner $(n,n)$ using only right and down steps. There are $m$ trap cells that cannot be entered (and the start and end cells are never traps). Count the number of valid paths modulo $10^9+7$.

## Input
First line gives $n$ and $m$. Then $m$ lines follow, each with two integers $y$ and $x$ giving a trap's row and column.

## Output
Print the number of valid paths modulo $10^9+7$.

## Constraints
- $1 \le n \le 10^6$
- $1 \le m \le 1000$
- $1 \le y,x \le n$
