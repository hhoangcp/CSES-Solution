# Nested Ranges Check

**CSES ID:** 2168  
**Full statement:** https://cses.fi/problemset/task/2168  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Given $n$ intervals, for each one report whether it contains some other interval and whether some other interval contains it. Range $[a,b]$ contains $[c,d]$ iff $a\le c$ and $d\le b$.

## Input
First line: integer $n$. Then $n$ lines, each with two integers $x$ and $y$ defining $[x,y]$. No two ranges are identical.

## Output
Print one line of $n$ values (1/0): whether range $i$ contains another. Then a second line: whether range $i$ is contained by another.

## Constraints
- $1 \le n \le 2 \cdot 10^5$
- $1 \le x < y \le 10^9$
