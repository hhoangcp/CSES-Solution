# Grid Coloring I

**CSES ID:** 3311  
**Full statement:** https://cses.fi/problemset/task/3311  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

An $n\times m$ grid holds characters `A`, `B`, `C`, or `D`. Replace each cell's character with a different one from the same alphabet so that no two orthogonally adjacent cells share a character. Output any valid recoloring, or `IMPOSSIBLE` if none exists.

## Input
First line: integers $n$ and $m$. Then $n$ lines of $m$ characters describing the grid.

## Output
Print $n$ lines of $m$ characters, the recolored grid, or `IMPOSSIBLE` if no solution exists.

## Constraints
- $1 \le n, m \le 500$
