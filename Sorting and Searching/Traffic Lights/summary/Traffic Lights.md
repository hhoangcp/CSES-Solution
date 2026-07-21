# Traffic Lights

**CSES ID:** 1163  
**Full statement:** https://cses.fi/problemset/task/1163  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

A street of length $x$ (positions $0$ to $x$) starts with no traffic lights. Lights are added one by one at given distinct positions, and after each addition you must report the longest segment of the street without any light.

## Input
First line: integers $x$ and $n$. Next line: $n$ integers $p_1,\ldots,p_n$ (distinct positions strictly between 0 and $x$).

## Output
Print the length of the longest light-free passage after each addition.

## Constraints
- $1 \le x \le 10^9$
- $1 \le n \le 2 \cdot 10^5$
- $0 < p_i < x$
