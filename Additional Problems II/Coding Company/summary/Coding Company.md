# Coding Company

**CSES ID:** 1665  
**Full statement:** https://cses.fi/problemset/task/1665  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Split $n$ coders (each with skill 0..100) into teams; a team's cost is the difference between the best and worst skill in it. Count the number of ways to form teams so that the total cost is at most $x$, modulo $10^9+7$.

## Input
First line: $n$ and $x$. Next line: $n$ skill levels $t_i$.

## Output
One integer: the number of valid divisions modulo $10^9+7$.

## Constraints
- $1 \le n \le 100$
- $0 \le x \le 5000$
- $0 \le t_i \le 100$
