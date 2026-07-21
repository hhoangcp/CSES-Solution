# Knuth Division

**CSES ID:** 2088  
**Full statement:** https://cses.fi/problemset/task/2088  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Starting from an array of $n$ numbers, repeatedly split a chosen subarray into two until every piece is a single element. Each split costs the sum of values in the chosen subarray. Find the minimum total cost of a full reduction.

## Input
First line: $n$. Second line: $n$ integers $x_1,\ldots,x_n$.

## Output
Print the minimum total cost.

## Constraints
- $1 \le n \le 5000$
- $1 \le x_i \le 10^9$
