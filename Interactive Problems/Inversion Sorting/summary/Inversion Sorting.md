# Inversion Sorting

**CSES ID:** 3140  
**Full statement:** https://cses.fi/problemset/task/3140  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Interactive problem. A hidden permutation of $1..n$ must be sorted by repeatedly reversing a chosen subarray; after each reversal the grader reports the inversion count. You win when inversions reach $0$.

## Input
Read $n$ first. Each turn print two indices $i, j$ to reverse that subarray, then read the resulting inversion count; $0$ means success and you terminate.

## Output
Index pairs `i j` for each reversal, one operation per turn.

## Constraints
- $1 \le n \le 1000$
- at most $4n$ reversal operations
