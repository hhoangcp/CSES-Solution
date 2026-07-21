# Pattern Positions

**CSES ID:** 2104  
**Full statement:** https://cses.fi/problemset/task/2104  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Given a text and several query patterns, for each pattern report the smallest starting index (1-based) at which it occurs in the text, or $-1$ if it does not occur at all.

## Input
The first line is the text of length $n$. The next line gives an integer $k$, followed by $k$ lines each containing one pattern. All strings use characters a–z.

## Output
For each pattern in order, print the earliest 1-based position where it appears, or $-1$.

## Constraints
- $1 \le n \le 10^5$
- $1 \le k \le 5 \cdot 10^5$
- total length of patterns $\le 5 \cdot 10^5$
