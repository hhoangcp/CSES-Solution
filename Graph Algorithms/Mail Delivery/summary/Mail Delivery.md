# Mail Delivery

**CSES ID:** 1691  
**Full statement:** https://cses.fi/problemset/task/1691  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

An undirected graph has $n$ crossings and $m$ streets. Find a closed route starting and ending at crossing $1$ that traverses each street exactly once.

## Input
$n$ and $m$, then $m$ undirected edges $a, b$.

## Output
The vertex sequence of the circuit, or `IMPOSSIBLE`.

## Constraints
- $2 \le n \le 10^5$
- $1 \le m \le 2 \cdot 10^5$
- $1 \le a,b \le n$
