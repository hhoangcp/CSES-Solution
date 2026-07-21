# Monsters

**CSES ID:** 1194  
**Full statement:** https://cses.fi/problemset/task/1194  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

On an $n \times m$ grid with walls, one start `A` and some monsters `M`, you and monsters move simultaneously one step per turn. Find a path from `A` to the boundary that never shares a cell with a monster, assuming monsters know your path.

## Input
$n, m$, then $n$ lines of $m$ characters (`.`, `#`, `A`, `M`).

## Output
`YES` plus the path length and a string of `U/D/L/R`, or `NO`.

## Constraints
- $1 \le n,m \le 1000$
