# Labyrinth

**CSES ID:** 1193  
**Full statement:** https://cses.fi/problemset/task/1193  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Given an $n \times m$ grid with floor, walls, a start `A` and an end `B`, find a shortest path from `A` to `B` using 4-directional moves and output it as a move string.

## Input
Two integers $n, m$, then $n$ lines of $m$ characters (`.`, `#`, `A`, `B`).

## Output
`YES` plus the path length and a string of `L/R/U/D`, or `NO` if unreachable.

## Constraints
- $1 \le n,m \le 1000$
