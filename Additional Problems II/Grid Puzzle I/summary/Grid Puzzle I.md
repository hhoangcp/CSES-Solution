# Grid Puzzle I

**CSES ID:** 2432  
**Full statement:** https://cses.fi/problemset/task/2432  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

In an $n \times n$ grid, mark cells so that exactly $a_i$ cells are chosen in row $i$ and exactly $b_j$ cells in column $j$. Output any valid marking or report that it is impossible.

## Input
First line: $n$. Next line: $a_1,\dots,a_n$. Last line: $b_1,\dots,b_n$.

## Output
$n$ lines of `X` (chosen) and `.` (not chosen), or just `-1` if impossible.

## Constraints
- $1 \le n \le 50$
- $0 \le a_i \le n$
- $0 \le b_j \le n$
