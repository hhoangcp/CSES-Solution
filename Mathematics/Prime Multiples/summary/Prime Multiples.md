# Prime Multiples

**CSES ID:** 2185  
**Full statement:** https://cses.fi/problemset/task/2185  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Given $k$ distinct primes and a bound $n$, count how many integers in $[1,n]$ are divisible by at least one of those primes.

## Input
The first line contains $n$ and $k$. The second line lists the $k$ primes $a_1, \dots, a_k$.

## Output
Print the count of integers in $[1,n]$ divisible by at least one given prime.

## Constraints
- $1 \le n \le 10^{18}$
- $1 \le k \le 20$
- $2 \le a_i \le n$
