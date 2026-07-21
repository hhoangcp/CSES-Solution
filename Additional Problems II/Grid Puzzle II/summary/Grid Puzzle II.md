# Grid Puzzle II

**CSES ID:** 2131  
**Full statement:** https://cses.fi/problemset/task/2131  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

An $n \times n$ grid has $c_{ij}$ coins per cell. Choose cells so that row $i$ contributes exactly $a_i$ and column $j$ exactly $b_j$ chosen cells, maximizing the total coins collected.

## Input
First line: $n$. Next line: $a_1,\dots,a_n$. Next line: $b_1,\dots,b_n$. Then $n$ lines of $n$ integers giving $c_{ij}$.

## Output
First the maximum coin total, then $n$ lines of `X`/`.` describing the chosen cells, or just `-1` if infeasible.

## Constraints
- $1 \le n \le 50$
- $0 \le a_i \le n$
- $0 \le b_j \le n$
- $0 \le c_{ij} \le 1000$
