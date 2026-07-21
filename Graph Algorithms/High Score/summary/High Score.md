# High Score

**CSES ID:** 1673  
**Full statement:** https://cses.fi/problemset/task/1673  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

A directed weighted graph has $n$ rooms and $m$ one-way tunnels; each tunnel adds weight $x$ (possibly negative) to your score and may be reused. Travel from room $1$ to room $n$ maximizing score; report $-1$ if it can be made arbitrarily large.

## Input
$n$ and $m$, then $m$ lines giving an edge $a \to b$ with weight $x$.

## Output
The maximum achievable score, or $-1$ if unbounded.

## Constraints
- $1 \le n \le 2500$
- $1 \le m \le 5000$
- $1 \le a,b \le n$
- $-10^9 \le x \le 10^9$
