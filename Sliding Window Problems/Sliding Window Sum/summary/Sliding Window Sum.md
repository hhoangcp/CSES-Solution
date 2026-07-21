# Sliding Window Sum

**CSES ID:** 3220  
**Full statement:** https://cses.fi/problemset/task/3220  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

The array is generated rather than read, with $x_1=x$ and $x_i=(ax_{i-1}+b)\bmod c$ from parameters $x,a,b,c$. For each sliding window of size $k$ compute the element sum, then output the xor of all those sums.

## Input
First line: $n$ and $k$. Second line: four integers $x,a,b,c$ for the generator.

## Output
Print a single integer: the xor of all $n-k+1$ window sums.

## Constraints
- $1 \le k \le n \le 10^7$
- $0 \le x, a, b \le 10^9$
- $1 \le c \le 10^9$
