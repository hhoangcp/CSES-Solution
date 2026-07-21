# Range Xor Queries

**CSES ID:** 1650  
**Full statement:** https://cses.fi/problemset/task/1650  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Given an array, answer queries asking for the bitwise XOR of all values in a range $[a,b]$.

## Input
First line gives $n$ and $q$. Second line lists the array values. The following $q$ lines each give two endpoints $a$ and $b$.

## Output
Print the XOR sum for each query.

## Constraints
- $1 \le n,q \le 2 \cdot 10^5$
- $1 \le x_i \le 10^9$
- $1 \le a \le b \le n$
