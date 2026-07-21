# Concert Tickets

**CSES ID:** 1091  
**Full statement:** https://cses.fi/problemset/task/1091  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

There are $n$ tickets with given prices and $m$ customers arriving in order, each stating the most they will pay. A customer gets the most expensive ticket not exceeding their limit, which is then removed.

## Input
First line: integers $n$ and $m$. Next line: $n$ ticket prices $h_1,\ldots,h_n$. Last line: $m$ maximum prices $t_1,\ldots,t_m$.

## Output
For each customer, print the price paid, or $-1$ if no ticket is affordable.

## Constraints
- $1 \le n, m \le 2 \cdot 10^5$
- $1 \le h_i, t_i \le 10^9$
