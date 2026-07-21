# Nearest Smaller Values

**CSES ID:** 1645  
**Full statement:** https://cses.fi/problemset/task/1645  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

For each position in an array, find the index of the nearest position to its left that holds a smaller value (or $0$ if none exists).

## Input
First line: integer $n$. Second line: $n$ integers $x_1,\ldots,x_n$.

## Output
Print $n$ integers: the nearest smaller left index for each position (1-indexed, $0$ if none).

## Constraints
- $1 \le n \le 2 \cdot 10^5$
- $1 \le x_i \le 10^9$
