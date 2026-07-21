# Sliding Window Xor

**CSES ID:** 3426  
**Full statement:** https://cses.fi/problemset/task/3426  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

The array is generated from $x,a,b,c$ with $x_1=x$ and $x_i=(ax_{i-1}+b)\bmod c$. For each sliding window of size $k$ compute the bitwise XOR of its elements, then output the xor of all those window xors.

## Input
First line: $n$ and $k$. Second line: four integers $x,a,b,c$ for the generator.

## Output
Print a single integer: the xor of all $n-k+1$ window xors.

## Constraints
- $1 \le k \le n \le 10^7$
- $0 \le x, a, b \le 10^9$
- $1 \le c \le 10^9$
