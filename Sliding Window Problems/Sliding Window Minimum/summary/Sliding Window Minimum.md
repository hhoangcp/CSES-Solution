# Sliding Window Minimum

**CSES ID:** 3221  
**Full statement:** https://cses.fi/problemset/task/3221  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Because the input is huge it is generated, not read element by element. From parameters $x,a,b,c$ the array satisfies $x_1=x$ and $x_i=(ax_{i-1}+b)\bmod c$. For each sliding window of size $k$ you need the minimum, but instead of printing them all you print their xor.

## Input
First line: $n$ and $k$. Second line: four integers $x,a,b,c$ for the generator.

## Output
Print a single integer: the xor of all $n-k+1$ window minimums.

## Constraints
- $1 \le k \le n \le 10^7$
- $0 \le x, a, b \le 10^9$
- $1 \le c \le 10^9$
