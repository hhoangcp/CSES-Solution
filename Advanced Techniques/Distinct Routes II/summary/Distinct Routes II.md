# Distinct Routes II

**CSES ID:** 2130  
**Full statement:** https://cses.fi/problemset/task/2130  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

A directed graph has $n$ rooms and $m$ teleporters. Each day you must travel from room $1$ to room $n$, and each teleporter may be used at most once across the whole game. Playing exactly $k$ days while paying one coin per teleporter use, find the minimum total coins and print the $k$ routes. If impossible, print $-1$.

## Input
First line: $n,m,k$. Then $m$ lines each with two integers $a,b$ (a teleporter $a \to b$). No two teleporters share both endpoints.

## Output
Print the minimum coin count, then $k$ route descriptions. If infeasible, print $-1$.

## Constraints
- $2 \le n \le 500$
- $1 \le m \le 1000$
- $1 \le k \le n-1$
- $1 \le a,b \le n$
