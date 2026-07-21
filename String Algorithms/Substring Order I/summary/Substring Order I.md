# Substring Order I

**CSES ID:** 2108  
**Full statement:** https://cses.fi/problemset/task/2108  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Consider the set of all distinct substrings of a given string, ordered lexicographically. Your task is to output the $k$th smallest one.

## Input
The first line contains a string of length $n$ over a–z. The second line contains the integer $k$.

## Output
Print the $k$th smallest distinct substring in lexicographic order.

## Constraints
- $1 \le n \le 10^5$
- $1 \le k \le \frac{n(n+1)}{2}$
- $k$ does not exceed the number of distinct substrings
