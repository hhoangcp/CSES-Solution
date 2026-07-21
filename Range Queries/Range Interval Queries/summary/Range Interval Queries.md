# Range Interval Queries

**CSES ID:** 3163  
**Full statement:** https://cses.fi/problemset/task/3163  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

You are given an array of $n$ integers and must answer queries that count how many indices $i$ lie in a positional range $[a,b]$ while also having value within a value range $[c,d]$.

## Input
First line gives $n$ and $q$. Second line lists the array values. The following $q$ lines each give four integers $a$, $b$, $c$, $d$.

## Output
Print the count for each query.

## Constraints
- $1 \le n,q \le 2 \cdot 10^5$
- $1 \le x_i \le 10^9$
- $1 \le a \le b \le n$
- $1 \le c \le d \le 10^9$
