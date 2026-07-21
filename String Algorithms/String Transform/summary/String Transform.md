# String Transform

**CSES ID:** 1113  
**Full statement:** https://cses.fi/problemset/task/1113  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

A string is transformed by appending a sentinel `#` (smaller than all letters), listing all cyclic rotations, sorting them lexicographically, and concatenating their last characters. Given the transformed string of length $n+1$, recover the original string of length $n$.

## Input
A single line containing the transformed string of length $n+1$; the original string used characters a–z plus the `#` sentinel.

## Output
Print the recovered original string of length $n$.

## Constraints
- $1 \le n \le 10^6$
