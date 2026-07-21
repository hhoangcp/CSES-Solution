# Nearest Campsites II

**CSES ID:** 3307  
**Full statement:** https://cses.fi/problemset/task/3307  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

On a grid with $n$ reserved campsites and $m$ free campsites under Manhattan distance, compute for each free campsite the distance to its closest reserved site.

## Input
Integers $n$ and $m$, then $n$ reserved coordinates, then $m$ free coordinates.

## Output
Print $m$ integers: the nearest-reserved distance for each free campsite in input order.

## Constraints
- $1 \le n, m \le 10^5$
- $1 \le x, y \le 10^6$
