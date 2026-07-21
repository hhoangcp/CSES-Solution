# SOS Bit Problem

**CSES ID:** 1654  
**Full statement:** https://cses.fi/problemset/task/1654  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Given a list of integers, for each element $x$ compute three counts: how many elements $y$ satisfy $x \mid y = x$, how many satisfy $x \wedge y = x$, and how many satisfy $x \wedge y \neq 0$.

## Input
First line: integer $n$. Second line: $n$ integers $x_1,\dots,x_n$.

## Output
$n$ lines, each with the three counts for the corresponding element.

## Constraints
- $1 \le n \le 2 \cdot 10^5$
- $1 \le x_i \le 10^6$
