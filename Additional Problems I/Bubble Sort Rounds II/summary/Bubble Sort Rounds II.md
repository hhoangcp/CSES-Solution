# Bubble Sort Rounds II

**CSES ID:** 3152  
**Full statement:** https://cses.fi/problemset/task/3152  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Each round of bubble sort scans left to right swapping out-of-order adjacent pairs. Given an array and a number $k$ of rounds (which may exceed the rounds needed to fully sort), output the array's contents after exactly $k$ rounds.

## Input
Two integers $n$ and $k$, then $n$ integers giving the array.

## Output
Print the $n$ array elements after $k$ rounds.

## Constraints
- $1 \le n \le 2 \cdot 10^5$
- $0 \le k \le 10^9$
- $1 \le x_i \le 10^9$
