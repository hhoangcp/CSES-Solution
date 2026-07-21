# Stick Divisions

**CSES ID:** 1161  
**Full statement:** https://cses.fi/problemset/task/1161  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

You have a stick of length $x$ that must be split into $n$ sticks of given lengths $d_i$ summing to $x$. Each split divides one stick into two and costs the length of the stick being split. Find the minimum total cost.

## Input
First line: $x$ and $n$. Second line: $n$ integers $d_1,\dots,d_n$.

## Output
One integer: the minimum cost of the division.

## Constraints
- $1 \le x \le 10^9$
- $1 \le n \le 2 \cdot 10^5$
- $\sum d_i = x$
