# Substring Order II

**CSES ID:** 2109  
**Full statement:** https://cses.fi/problemset/task/2109  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Consider all substrings of the given string, counted with multiplicity (each starting position counted separately), sorted lexicographically. Output the $k$th element of this multiset.

## Input
The first line contains a string of length $n$ over a–z. The second line contains the integer $k$.

## Output
Print the $k$th smallest substring (with multiplicity) in lexicographic order.

## Constraints
- $1 \le n \le 10^5$
- $1 \le k \le \frac{n(n+1)}{2}$
