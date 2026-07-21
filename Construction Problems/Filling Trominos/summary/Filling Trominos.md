# Filling Trominos

**CSES ID:** 2423  
**Full statement:** https://cses.fi/problemset/task/2423  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Decide whether an $n \times m$ grid can be tiled completely with L-shaped trominoes (each covering three unit cells). When a tiling exists, you must also produce one and label cells with letters so that adjacent cells share a letter exactly when they belong to the same tromino.

## Input
First line: integer $t$ (number of tests). Then $t$ lines, each with two integers $n$ and $m$.

## Output
For each test print `YES` followed by an $n \times m$ letter grid when possible, otherwise print `NO`.

## Constraints
- $1 \le t \le 100$
- $1 \le n,m \le 100$
