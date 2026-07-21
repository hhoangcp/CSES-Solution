# Weird Algorithm

**CSES ID:** 1068  
**Full statement:** https://cses.fi/problemset/task/1068  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Starting from a positive integer $n$, repeatedly replace $n$ by $n/2$ when even and $3n+1$ when odd, stopping at 1 (the Collatz process). Print every value produced along the way, beginning with the initial $n$.

## Input
A single integer $n$.

## Output
Print all values visited during the process on one line, ending with 1.

## Constraints
- $1 \le n \le 10^6$
