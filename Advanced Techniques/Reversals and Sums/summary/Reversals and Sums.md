# Reversals and Sums

**CSES ID:** 2074  
**Full statement:** https://cses.fi/problemset/task/2074  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Process $m$ operations on an array of $n$ integers: either reverse a contiguous subarray, or query the sum of a contiguous subarray. Output the result of each sum query.

## Input
First line: $n,m$. Second line: $n$ integers $x_1,\ldots,x_n$. Then $m$ lines, each with three integers $t,a,b$: $t=1$ reverses positions $a\ldots b$, $t=2$ queries their sum.

## Output
Print the answer to every operation with $t=2$.

## Constraints
- $1 \le n \le 2 \cdot 10^5$
- $1 \le m \le 10^5$
- $0 \le x_i \le 10^9$
- $1 \le a \le b \le n$
