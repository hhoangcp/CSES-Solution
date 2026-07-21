# Raab Game II

**CSES ID:** 3400  
**Full statement:** https://cses.fi/problemset/task/3400  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Two players each hold the cards $1,2,\dots,n$. Each round both reveal one card: the higher card wins a point, ties score nothing. Given $n$ and the final scores $a$ and $b$, count how many distinct games can produce that outcome, modulo $10^9+7$.

## Input
First line gives $t$, the number of tests. Then $t$ lines follow, each with $n$, $a$, and $b$.

## Output
For each test, print the number of possible games modulo $10^9+7$.

## Constraints
- $1 \le t \le 1000$
- $1 \le n \le 5000$
- $0 \le a,b \le n$
