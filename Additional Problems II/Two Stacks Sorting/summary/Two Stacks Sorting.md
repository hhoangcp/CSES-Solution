# Two Stacks Sorting

**CSES ID:** 2402  
**Full statement:** https://cses.fi/problemset/task/2402  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

You are given a permutation of $1,\dots,n$ as an input stream. Build the sorted sequence $1,2,\dots,n$ using two stacks: each move either pushes the next input value onto one of the stacks or pops a stack top to the output. For each input value output which stack (1 or 2) it is pushed onto, or report impossibility.

## Input
First line: $n$. Second line: $n$ integers, the input list.

## Output
Print $n$ integers (1 or 2) indicating the stack for each input value, or `IMPOSSIBLE` if no solution exists.

## Constraints
- $1 \le n \le 2 \cdot 10^5$
