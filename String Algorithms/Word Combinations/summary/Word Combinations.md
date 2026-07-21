# Word Combinations

**CSES ID:** 1731  
**Full statement:** https://cses.fi/problemset/task/1731  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

You are given a target string and a dictionary of distinct words. Count how many ways the string can be formed by concatenating dictionary words (each word usable any number of times), with the result taken modulo $10^9+7$.

## Input
The first line holds the target string of $n$ characters (a–z). The second line gives the integer $k$, followed by $k$ lines, one dictionary word each (a–z).

## Output
Print one integer: the number of ways modulo $10^9+7$.

## Constraints
- $1 \le n \le 5000$
- $1 \le k \le 10^5$
- total length of the words $\le 10^6$
