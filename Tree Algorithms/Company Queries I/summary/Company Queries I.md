# Company Queries I

**CSES ID:** 1687  
**Full statement:** https://cses.fi/problemset/task/1687  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

A company's employees form a rooted tree where each person (except the director) has one direct boss. For each query you must climb the chain of command from a given employee by a fixed number of levels and report that ancestor.

## Input
First line gives $n$ and $q$. The next line gives the boss of every employee $2 \dots n$ (with boss index smaller than the employee). Then $q$ lines each give an employee $x$ and a level count $k$.

## Output
For each query print the ancestor $k$ levels above $x$, or $-1$ if none exists.

## Constraints
- $1 \le n,q \le 2 \cdot 10^5$
- $1 \le e_i \le i-1$
- $1 \le x \le n$
- $1 \le k \le n$
