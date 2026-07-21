# Collecting Numbers

**CSES ID:** 2216  
**Full statement:** https://cses.fi/problemset/task/2216  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

You are given a permutation of $1\ldots n$. On each round you scan the array left to right and collect the values $1,2,\ldots,n$ in increasing order, taking each remaining value when you encounter it. Find the number of rounds needed to collect everything.

## Input
First line: integer $n$. Next line: $n$ integers $x_1,\ldots,x_n$ forming a permutation of $1\ldots n$.

## Output
Print one integer: the number of rounds needed.

## Constraints
- $1 \le n \le 2 \cdot 10^5$
