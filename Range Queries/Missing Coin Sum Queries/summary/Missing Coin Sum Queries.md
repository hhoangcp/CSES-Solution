# Missing Coin Sum Queries

**CSES ID:** 2184  
**Full statement:** https://cses.fi/problemset/task/2184  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

You have $n$ coins with positive integer values. For each query asking about a contiguous subarray of coins, you must find the smallest positive sum that cannot be formed using a subset of those coins.

## Input
First line gives $n$ and $q$. Second line lists the coin values. The following $q$ lines each give two indices $a$ and $b$ bounding the usable subarray.

## Output
Print the smallest unformable positive sum for each query.

## Constraints
- $1 \le n, q \le 2 \cdot 10^5$
- $1 \le x_i \le 10^9$
- $1 \le a \le b \le n$
