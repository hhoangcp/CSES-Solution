# Nearest Campsites I

**CSES ID:** 3306  
**Full statement:** https://cses.fi/problemset/task/3306  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

You are given two sets of grid points: $n$ reserved campsites and $m$ free campsites, with distance measured by Manhattan metric. For each free campsite, find the distance to its closest reserved site, and report the maximum of these nearest distances.

## Input
Integers $n$ and $m$, then $n$ reserved-site coordinates, then $m$ free-site coordinates.

## Output
Print the maximum distance from a free site to its nearest reserved site.

## Constraints
- $1 \le n, m \le 10^5$
- $1 \le x, y \le 10^6$
