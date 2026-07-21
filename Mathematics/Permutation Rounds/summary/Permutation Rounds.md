# Permutation Rounds

**CSES ID:** 3398  
**Full statement:** https://cses.fi/problemset/task/3398  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Starting from the array $[1,2,\dots,n]$, each round simultaneously sends the element at position $i$ to position $p_i$ for a given permutation $p$. Find the smallest positive number of rounds after which the array becomes sorted again.

## Input
The first line is $n$, the second line gives $p_1, \dots, p_n$.

## Output
Print the number of rounds modulo $10^9+7$.

## Constraints
- $1 \le n \le 2 \cdot 10^5$
