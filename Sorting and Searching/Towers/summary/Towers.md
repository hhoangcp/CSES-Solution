# Towers

**CSES ID:** 1073  
**Full statement:** https://cses.fi/problemset/task/1073  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Cubes arrive in a fixed order; each may either start a new tower or be placed on top of an existing tower, but a cube on top must be smaller than the one beneath it. Minimize the number of towers.

## Input
First line: integer $n$. Next line: $n$ integers $k_1,\ldots,k_n$.

## Output
Print one integer: the minimum number of towers.

## Constraints
- $1 \le n \le 2 \cdot 10^5$
- $1 \le k_i \le 10^9$
