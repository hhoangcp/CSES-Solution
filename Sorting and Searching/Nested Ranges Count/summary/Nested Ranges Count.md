# Nested Ranges Count

**CSES ID:** 2169  
**Full statement:** https://cses.fi/problemset/task/2169  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Given $n$ intervals, for each one count how many other intervals it contains and how many other intervals contain it. Range $[a,b]$ contains $[c,d]$ iff $a\le c$ and $d\le b$.

## Input
First line: integer $n$. Then $n$ lines, each with two integers $x$ and $y$ defining $[x,y]$. No two ranges are identical.

## Output
Print one line of $n$ counts: how many other ranges range $i$ contains. Then a second line: how many other ranges contain range $i$.

## Constraints
- $1 \le n \le 2 \cdot 10^5$
- $1 \le x < y \le 10^9$
