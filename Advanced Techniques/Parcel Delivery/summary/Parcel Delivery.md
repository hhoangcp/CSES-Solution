# Parcel Delivery

**CSES ID:** 2121  
**Full statement:** https://cses.fi/problemset/task/2121  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

A directed network of $n$ cities and $m$ routes exists, where route $a\to b$ carries capacity $r$ parcels each at unit cost $c$. Send exactly $k$ parcels from city $1$ (Syrjälä) to city $n$ (Lehmälä) at minimum total cost, or report infeasibility with $-1$.

## Input
First line: $n,m,k$. Then $m$ lines, each with four integers $a,b,r,c$ describing a route.

## Output
Print the minimum total cost, or $-1$ if no solution exists.

## Constraints
- $2 \le n \le 500$
- $1 \le m \le 1000$
- $1 \le k \le 100$
- $1 \le a,b \le n$
- $1 \le r,c \le 1000$
