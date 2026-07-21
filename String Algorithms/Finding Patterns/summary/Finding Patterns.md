# Finding Patterns

**CSES ID:** 2102  
**Full statement:** https://cses.fi/problemset/task/2102  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

You are given a text and several query patterns. For each pattern, decide whether it occurs at least once anywhere inside the text.

## Input
The first line is the text of length $n$. The second line gives an integer $k$, followed by $k$ lines each containing one pattern. All strings use characters a–z.

## Output
For each pattern in order, print "YES" if it appears in the text, otherwise "NO".

## Constraints
- $1 \le n \le 10^5$
- $1 \le k \le 5 \cdot 10^5$
- total length of patterns $\le 5 \cdot 10^5$
