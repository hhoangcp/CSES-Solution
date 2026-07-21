# Tree Isomorphism I

**CSES ID:** 1700  
**Full statement:** https://cses.fi/problemset/task/1700  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Given two rooted trees (root = node 1) on the same number $n$ of labeled nodes, decide for each test case whether they are isomorphic as rooted trees.

## Input
First line: $t$ test cases. For each: an integer $n$, then $n-1$ edges of tree 1, then $n-1$ edges of tree 2.

## Output
For each test, print `YES` if the trees are isomorphic, else `NO`.

## Constraints
- $1 \le t \le 1000$
- $2 \le n \le 10^5$
- sum of all $n$ is at most $10^5$
