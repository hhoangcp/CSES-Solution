# Subarray Sum Queries II

**CSES ID:** 3226  
**Full statement:** https://cses.fi/problemset/task/3226  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

You are given an array and several queries; each query asks for the maximum sum of a contiguous subarray that lies fully inside a queried range $[a,b]$. The empty subarray (sum 0) is allowed.

## Input
First line gives $n$ and $q$. Second line lists the array values. The following $q$ lines each give two endpoints $a$ and $b$.

## Output
Print the maximum subarray sum inside $[a,b]$ for each query.

## Constraints
- $1 \le n, q\le 2 \cdot 10^5$
- $-10^9 \le x_i \le 10^9$
- $1 \le a \le b \le n$
