# Coin Collector

**CSES ID:** 1686  
**Full statement:** https://cses.fi/problemset/task/1686  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

A directed graph has $n$ rooms, each holding some coins, and $m$ one-way tunnels. Pick a start and end room to maximize total coins collected along a walk through the tunnels.

## Input
$n$ and $m$, then $n$ coin counts, then $m$ directed edges $a \to b$.

## Output
A single integer: the maximum collectable coin total.

## Constraints
- $1 \le n \le 10^5$
- $1 \le m \le 2 \cdot 10^5$
- $1 \le k_i \le 10^9$
- $1 \le a,b \le n$
