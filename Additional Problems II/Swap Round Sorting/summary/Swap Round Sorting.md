# Swap Round Sorting

**CSES ID:** 1698  
**Full statement:** https://cses.fi/problemset/task/1698  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

You are given a permutation of $1,\dots,n$. Sort it using swap rounds: in each round, any number of disjoint pairs of positions may be swapped simultaneously. Find the minimum number of rounds and a corresponding sequence of swaps.

## Input
First line: $n$. Second line: $n$ integers $x_1,\dots,x_n$.

## Output
First the minimum round count $k$. Then for each round, the number of swaps followed by the index pairs swapped. Any valid solution is accepted.

## Constraints
- $1 \le n \le 2 \cdot 10^5$
