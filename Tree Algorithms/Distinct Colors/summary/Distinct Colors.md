# Distinct Colors

**CSES ID:** 1139  
**Full statement:** https://cses.fi/problemset/task/1139  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

A rooted tree has a color on each node. For every node you must report how many distinct colors appear in its subtree.

## Input
First line gives $n$. The next line lists the $n$ colors $c_1 \dots c_n$. Then $n-1$ edges.

## Output
Print $n$ integers: the count of distinct colors in the subtree of each node $1 \dots n$.

## Constraints
- $1 \le n \le 2 \cdot 10^5$
- $1 \le a,b \le n$
- $1 \le c_i \le 10^9$
