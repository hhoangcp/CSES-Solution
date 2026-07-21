# Replace with Difference

**CSES ID:** 3159  
**Full statement:** https://cses.fi/problemset/task/3159  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Starting from an array of $n$ integers, perform $n-1$ operations: each picks two numbers, removes both and inserts $|a-b|$, until one number remains. Produce an operation sequence that leaves 0, or report impossibility.

## Input
First line: $n$. Next line: $n$ integers $x_1,\dots,x_n$.

## Output
$n-1$ lines each with the two chosen numbers, or just `-1` if impossible. Any valid solution is accepted.

## Constraints
- $2 \le n \le 1000$
- $1 \le x_i \le 1000$
