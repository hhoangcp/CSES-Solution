# Inversion Probability

**CSES ID:** 1728  
**Full statement:** https://cses.fi/problemset/task/1728  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

An array of length $n$ is generated so that position $i$ holds a uniform random integer in $[1, r_i]$. An inversion is a pair $a<b$ with $x_a>x_b$. Compute the expected number of inversions to six decimals.

## Input
The first line is $n$, the second line gives $r_1, \dots, r_n$.

## Output
Print the expected number of inversions rounded to six decimal places (round half to even).

## Constraints
- $1 \le n \le 100$
- $1 \le r_i \le 100$
