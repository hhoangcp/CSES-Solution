# Palindrome Queries

**CSES ID:** 2420  
**Full statement:** https://cses.fi/problemset/task/2420  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

You are given a string of length $n$ (1-indexed) and must process a sequence of operations. A point update changes the character at a chosen position, and a query asks whether a given range forms a palindrome.

## Input
The first line contains two integers $n$ and $m$. The next line holds the string of $n$ characters. Then follow $m$ operation lines, either "1 $k$ $x$" (update position $k$ to character $x$) or "2 $a$ $b$" (query range $[a,b]$).

## Output
For each type-2 operation, print "YES" if the queried range is a palindrome, otherwise "NO".

## Constraints
- $1 \le n, m \le 2 \cdot 10^5$
- $1 \le k \le n$
- $1 \le a \le b \le n$
