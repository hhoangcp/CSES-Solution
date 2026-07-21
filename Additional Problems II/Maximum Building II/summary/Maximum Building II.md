# Maximum Building II

**CSES ID:** 1148  
**Full statement:** https://cses.fi/problemset/task/1148  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

A forest map of size $n \times m$ has empty cells (`.`) and tree cells (`*`). You may place a rectangular building covering only empty cells (no tree cutting). For every possible building height $h$ and width $w$, output the number of distinct placements of an $h \times w$ rectangle.

## Input
First line: $n$ and $m$. Then $n$ lines of $m$ characters (`.` or `*`).

## Output
Print $n$ lines, each with $m$ integers: entry at row $h$, column $w$ gives the count of $h \times w$ placements.

## Constraints
- $1 \le n, m \le 1000$
