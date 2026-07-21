# Collecting Numbers Distribution

**CSES ID:** 3157  
**Full statement:** https://cses.fi/problemset/task/3157  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

A permutation of $1 \dots n$ is scanned left to right each round, collecting the largest possible increasing run starting from the smallest uncollected value, until all numbers are gathered. For each $k=1,\dots,n$, count how many of the $n!$ permutations need exactly $k$ rounds. Answers are modulo $10^9+7$.

## Input
A single line containing the integer $n$.

## Output
Print $n$ values, the count of permutations requiring exactly $k$ rounds, modulo $10^9+7$.

## Constraints
- $1 \le n \le 5000$
