# Grid Completion

**CSES ID:** 2429  
**Full statement:** https://cses.fi/problemset/task/2429  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Build an $n \times n$ grid in which every row and column contains exactly one `A` and one `B`. Some cells are pre-filled; you may assume no row or column already has more than one `A` or one `B`. Count the number of ways to fill the remaining cells, modulo $10^9+7$.

## Input
First line gives $n$. Then $n$ lines follow, each with $n$ characters (`.` for empty, or `A`/`B`).

## Output
Print one integer, the number of valid completions modulo $10^9+7$.

## Constraints
- $2 \le n \le 500$
