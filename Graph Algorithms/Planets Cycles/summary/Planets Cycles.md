# Planets Cycles

**CSES ID:** 1751  
**Full statement:** https://cses.fi/problemset/task/1751  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

There are $n$ planets, each with a single teleporter target $t_i$. Starting from each planet, count how many teleportations occur before you land on a previously visited planet.

## Input
$n$, then $n$ integers $t_1, \dots, t_n$ (with $t_i$ possibly equal to $i$).

## Output
$n$ integers, the count for each starting planet.

## Constraints
- $1 \le n \le 2 \cdot 10^5$
- $1 \le t_i \le n$
