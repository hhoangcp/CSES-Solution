# Bit Inversions

**CSES ID:** 1188  
**Full statement:** https://cses.fi/problemset/task/1188  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

You are given a binary string of length $n$ and a sequence of single-bit flips. After each flip you must report the length of the longest run of equal bits currently in the string.

## Input
A bit string of length $n$, then an integer $m$, then $m$ positions to flip.

## Output
After each flip, print the maximum run length of identical bits.

## Constraints
- $1 \le n \le 2 \cdot 10^5$
- $1 \le m \le 2 \cdot 10^5$
- $1 \le x_i \le n$
