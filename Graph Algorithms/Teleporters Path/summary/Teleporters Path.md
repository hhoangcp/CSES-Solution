# Teleporters Path

**CSES ID:** 1693  
**Full statement:** https://cses.fi/problemset/task/1693  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

In a directed graph, find a trail from level $1$ to level $n$ that uses every teleporter exactly once, or report impossibility.

## Input
$n$ and $m$, then $m$ directed edges $a \to b$ (all pairs distinct).

## Output
$m+1$ integers: the level visit sequence, or `IMPOSSIBLE`.

## Constraints
- $2 \le n \le 10^5$
- $1 \le m \le 2 \cdot 10^5$
- $1 \le a,b \le n$
