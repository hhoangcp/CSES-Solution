# Counting Towers

**CSES ID:** 2413  
**Full statement:** https://cses.fi/problemset/task/2413  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Build a tower of width $2$ and height $n$ from blocks with integer side lengths (unlimited supply). Count distinct towers, where mirrored/rotated variants that look different count separately.

## Input
An integer $t$, then $t$ lines each with an integer $n$ (the height).

## Output
For each test, the number of towers modulo $10^9+7$.

## Constraints
- $1 \le t \le 100$
- $1 \le n \le 10^6$
