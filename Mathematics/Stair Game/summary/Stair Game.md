# Stair Game

**CSES ID:** 1099  
**Full statement:** https://cses.fi/problemset/task/1099  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

A staircase has $n$ steps, each with some balls. A move picks a step $k>1$ holding at least one ball and moves any positive number of balls from step $k$ to step $k-1$; the last to move wins. Decide the winner under optimal play.

## Input
The first line is $t$. Each test gives $n$ followed by $n$ integers $p_1, \dots, p_n$ (balls per step).

## Output
For each test print `first` or `second` (second wins if there are no legal moves).

## Constraints
- $1 \le t \le 2 \cdot 10^5$
- $1 \le n \le 2 \cdot 10^5$
- $0 \le p_i \le 10^9$
- $\sum n \le 2 \cdot 10^5$
