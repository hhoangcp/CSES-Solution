# Tree Coin Collecting I

**CSES ID:** 3114  
**Full statement:** https://cses.fi/problemset/task/3114  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

You are given a tree of $n$ nodes, some marked as holding a coin. Answer $q$ queries: for a pair $(a,b)$, find the length of the shortest walk from $a$ to $b$ that passes through at least one coin-holding node.

## Input
First line: $n$ and $q$. Second line: $n$ values $c_i \in \{0,1\}$ (at least one is 1). Then $n-1$ tree edges $a,b$. Finally $q$ query lines, each with endpoints $a,b$.

## Output
Print $q$ integers, one per query.

## Constraints
- $1 \le n, q \le 2 \cdot 10^5$
- $1 \le a, b \le n$
