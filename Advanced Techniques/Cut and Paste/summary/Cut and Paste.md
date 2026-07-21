# Cut and Paste

**CSES ID:** 2072  
**Full statement:** https://cses.fi/problemset/task/2072  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Given a string of length $n$, process $m$ cut-paste operations: each takes the substring from position $a$ to $b$ (1-indexed) and moves it to the end of the string. Output the resulting string after all operations.

## Input
First line: $n$ and $m$. Second line: a string of $n$ uppercase letters. Then $m$ lines, each with two integers $a$ and $b$.

## Output
Print the final string.

## Constraints
- $1 \le n,m \le 2 \cdot 10^5$
- $1 \le a \le b \le n$
