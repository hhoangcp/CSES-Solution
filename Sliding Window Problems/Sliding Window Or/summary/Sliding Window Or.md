# Sliding Window Or

**CSES ID:** 3405  
**Full statement:** https://cses.fi/problemset/task/3405  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

The array is too large to read directly, so it is generated from $x,a,b,c$ with $x_1=x$ and $x_i=(ax_{i-1}+b)\bmod c$. For every sliding window of size $k$ compute the bitwise OR of its elements, then output the xor of all those ORs.

## Input
First line: $n$ and $k$. Second line: four integers $x,a,b,c$ for the generator.

## Output
Print a single integer: the xor of all $n-k+1$ window ORs.

## Constraints
- $1 \le k \le n \le 10^7$
- $0 \le x, a, b \le 10^9$
- $1 \le c \le 10^9$
