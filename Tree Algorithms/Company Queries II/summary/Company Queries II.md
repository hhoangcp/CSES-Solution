# Company Queries II

**CSES ID:** 1688  
**Full statement:** https://cses.fi/problemset/task/1688  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Employees form a rooted hierarchy (a tree) with the director at the root. Each query names two employees and asks for their lowest common ancestor — the deepest boss that is an ancestor of both.

## Input
First line gives $n$ and $q$. The next line lists the boss of each employee $2 \dots n$. Then $q$ lines each give two employees $a$ and $b$.

## Output
For each query print the lowest common boss of $a$ and $b$.

## Constraints
- $1 \le n,q \le 2 \cdot 10^5$
- $1 \le e_i \le i-1$
- $1 \le a,b \le n$
