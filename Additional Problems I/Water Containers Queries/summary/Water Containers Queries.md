# Water Containers Queries

**CSES ID:** 3214  
**Full statement:** https://cses.fi/problemset/task/3214  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Two containers of capacities $a$ and $b$ start empty; allowed moves are filling, emptying, or pouring between them (each pour fills or empties one container), and the goal is to end with exactly $x$ units in container $A$. Answer many test cases: is it possible?

## Input
An integer $n$, then $n$ lines each with $a$, $b$, and $x$.

## Output
For each test case print `YES` or `NO`.

## Constraints
- $1 \le n \le 1000$
- $1 \le a, b, x \le 10^9$
