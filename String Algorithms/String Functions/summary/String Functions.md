# String Functions

**CSES ID:** 2107  
**Full statement:** https://cses.fi/problemset/task/2107  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

For a string indexed $1,2,\dots,n$, compute two arrays. The Z-array $z(i)$ is the longest substring starting at position $i$ that is also a prefix of the whole string, with $z(1)=0$. The prefix-function array $\pi(i)$ is the longest proper prefix of the string that is also a suffix of the prefix ending at position $i$.

## Input
A single line with a string of length $n$ over characters a–z.

## Output
Print two lines: the first with the $z$ values, the second with the $\pi$ values, each space-separated.

## Constraints
- $1 \le n \le 10^6$
