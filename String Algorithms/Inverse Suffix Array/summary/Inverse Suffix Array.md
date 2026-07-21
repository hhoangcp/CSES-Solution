# Inverse Suffix Array

**CSES ID:** 3225  
**Full statement:** https://cses.fi/problemset/task/3225  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

You are given a permutation of $1,2,\dots,n$ that purports to be the suffix array of some string (the lexicographic ordering of the string's suffixes). Reconstruct any string over a–z consistent with this ordering, or report that no such string exists.

## Input
The first line contains an integer $n$. The second line contains $n$ integers forming the proposed suffix array.

## Output
Print any valid string of length $n$ over a–z matching the suffix array, or $-1$ if none exists.

## Constraints
- $1 \le n \le 10^5$
