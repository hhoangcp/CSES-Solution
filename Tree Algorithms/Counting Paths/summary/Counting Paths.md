# Counting Paths

**CSES ID:** 1136  
**Full statement:** https://cses.fi/problemset/task/1136  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

You are given a tree and a list of node-to-node paths. For every node you must report how many of the listed paths pass through it. Treat each path as the unique simple route between its endpoints.

## Input
First line gives $n$ and $m$. Then $n-1$ edge lines, followed by $m$ lines each specifying a path by its two endpoints $a$ and $b$.

## Output
Print $n$ integers: the number of given paths containing each node $1 \dots n$.

## Constraints
- $1 \le n, m \le 2 \cdot 10^5$
- $1 \le a,b \le n$
