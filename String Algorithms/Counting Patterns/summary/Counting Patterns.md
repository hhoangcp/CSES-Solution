# Counting Patterns

**CSES ID:** 2103  
**Full statement:** https://cses.fi/problemset/task/2103  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Given a text and several query patterns, you must count, for each pattern, how many starting positions in the text match it exactly.

## Input
The first line is the text of length $n$. The second line gives an integer $k$, followed by $k$ lines each containing one pattern. All strings use characters a–z.

## Output
For each pattern in order, print one integer: its number of occurrences in the text.

## Constraints
- $1 \le n \le 10^5$
- $1 \le k \le 5 \cdot 10^5$
- total length of patterns $\le 5 \cdot 10^5$
