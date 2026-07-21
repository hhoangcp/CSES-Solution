# Apples and Bananas

**CSES ID:** 2111  
**Full statement:** https://cses.fi/problemset/task/2111  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

You are given multiset weights of apples and bananas, each an integer in $1\ldots k$. For every combined weight $w$ from $2$ to $2k$, count how many apple-banana pairs have total weight $w$.

## Input
First line: $k,n,m$. Second line: $n$ apple weights. Third line: $m$ banana weights.

## Output
Print $2k-1$ integers, the pair counts for $w=2,3,\ldots,2k$.

## Constraints
- $1 \le k,n,m \le 2 \cdot 10^5$
- $1 \le a_i,b_i \le k$
