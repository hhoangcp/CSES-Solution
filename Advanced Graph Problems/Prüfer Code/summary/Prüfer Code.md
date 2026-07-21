# Prüfer Code

**CSES ID:** 1134  
**Full statement:** https://cses.fi/problemset/task/1134  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

The Prüfer code of an $n$-node tree is a length-$n-2$ sequence built by repeatedly removing the lowest-numbered leaf and appending its sole neighbor's label. Given such a code, reconstruct the original labeled tree.

## Input
First line: $n$. Second line: the $n-2$ integers of the Prüfer code.

## Output
Print $n-1$ lines, each with an edge's endpoints $a,b$; any ordering of edges is accepted.

## Constraints
- $3 \le n \le 2 \cdot 10^5$
- $1 \le a, b \le n$
