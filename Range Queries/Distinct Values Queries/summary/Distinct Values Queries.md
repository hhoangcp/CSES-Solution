# Distinct Values Queries

**CSES ID:** 1734  
**Full statement:** https://cses.fi/problemset/task/1734  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

You are given an array and a set of range queries. For each query interval you must report how many different values appear inside that interval.

## Input
First line gives the array length $n$ and query count $q$. The second line lists the $n$ array elements. The final $q$ lines each give two endpoints $a$ and $b$ of a range.

## Output
For each query, print the count of distinct values in that range.

## Constraints
- $1 \le n,q \le 2 \cdot 10^5$
- $1 \le x_i \le 10^9$
- $1 \le a \le b \le n$
