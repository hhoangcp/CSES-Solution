# Factory Machines

**CSES ID:** 1620  
**Full statement:** https://cses.fi/problemset/task/1620  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

A factory has $n$ machines; machine $i$ needs $k_i$ seconds to produce one item. All machines can run in parallel and you must produce $t$ items total.

## Input
First line: integers $n$ and $t$. Next line: $n$ integers $k_1,\ldots,k_n$.

## Output
Print one integer: the minimum time needed to produce $t$ items.

## Constraints
- $1 \le n \le 2 \cdot 10^5$
- $1 \le t \le 10^9$
- $1 \le k_i \le 10^9$
