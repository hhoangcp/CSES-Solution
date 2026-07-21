# Corner Subgrid Check

**CSES ID:** 3360  
**Full statement:** https://cses.fi/problemset/task/3360  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

You are given an $n \times n$ grid filled with the first $k$ uppercase letters. A subgrid is valid if both its height and width are at least two and all four corner cells hold the same letter. For each of the $k$ letters, determine whether some valid subgrid has that letter at its corners.

## Input
First line: $n$ and $k$. Then $n$ lines, each a string of $n$ uppercase letters (the first $k$ letters).

## Output
Print $k$ lines, each `YES` or `NO` for the corresponding letter.

## Constraints
- $1 \le n \le 3000$
- $1 \le k \le 26$
