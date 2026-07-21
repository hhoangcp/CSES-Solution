# Apartments

**CSES ID:** 1084  
**Full statement:** https://cses.fi/problemset/task/1084  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

You are given desired sizes for $n$ applicants and actual sizes for $m$ apartments, together with a tolerance $k$. Each applicant accepts any apartment whose size lies within $k$ of their wish. The goal is to maximize how many applicants get an apartment.

## Input
First line: three integers $n$, $m$, $k$. Next line: $n$ desired sizes $a_1,\ldots,a_n$. Last line: $m$ apartment sizes $b_1,\ldots,b_m$.

## Output
Print one integer: the maximum number of applicants that can receive an apartment.

## Constraints
- $1 \le n, m \le 2 \cdot 10^5$
- $0 \le k \le 10^9$
- $1 \le a_i, b_i \le 10^9$
