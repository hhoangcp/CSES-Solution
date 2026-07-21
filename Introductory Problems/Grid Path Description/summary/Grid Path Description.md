# Grid Path Description

**CSES ID:** 1625  
**Full statement:** https://cses.fi/problemset/task/1625  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

On a $7\times 7$ grid a path from the upper-left square to the lower-left square uses exactly 48 moves along directions `U`, `D`, `L`, `R`. Given a 48-character pattern that may also contain `?` (any direction), count how many valid paths match it (staying on the board and never crossing itself).

## Input
A single line with a 48-character string over `?`, `U`, `D`, `L`, `R`.

## Output
Print one integer: the number of matching paths.

## Constraints
- Grid fixed at $7 \times 7$, description length fixed at 48
