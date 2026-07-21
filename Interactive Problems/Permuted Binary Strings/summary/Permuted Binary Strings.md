# Permuted Binary Strings

**CSES ID:** 3228  
**Full statement:** https://cses.fi/problemset/task/3228  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Interactive problem. A hidden permutation $a$ of $1..n$ must be recovered. You submit a binary string $b$ of length $n$ and receive the string $b_{a_1}b_{a_2}\dots b_{a_n}$, i.e. $b$ permuted by $a$.

## Input
Read $n$ first. Protocol: print `? b` (bits $b_i \in \{0,1\}$) to get the permuted string; print `! a_1 ... a_n` to report the permutation and terminate.

## Output
Bit-string queries and a final permutation line, flushing after each.

## Constraints
- $1 \le n \le 1000$
- at most $10$ `?` queries
