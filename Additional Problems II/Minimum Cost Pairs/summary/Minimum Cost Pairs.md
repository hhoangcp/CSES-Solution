# Minimum Cost Pairs

**CSES ID:** 3402  
**Full statement:** https://cses.fi/problemset/task/3402  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Given $n$ integers, form exactly $k$ disjoint pairs; a pair $(a,b)$ costs $|a-b|$. For each $k=1,\dots,\lfloor n/2\rfloor$ find the minimum total pairing cost.

## Input
First line: $n$. Next line: $n$ integers $x_1,\dots,x_n$.

## Output
Print $\lfloor n/2 \rfloor$ integers: the minimum costs for $k=1,\dots,\lfloor n/2\rfloor$.

## Constraints
- $2 \le n \le 2 \cdot 10^5$
- $1 \le x_i \le 10^9$
