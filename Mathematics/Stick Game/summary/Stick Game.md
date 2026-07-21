# Stick Game

**CSES ID:** 1729  
**Full statement:** https://cses.fi/problemset/task/1729  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

A take-away game: a fixed set $P$ of allowed move sizes, two players alternate removing a value from $P$ sticks from a single heap, and the player taking the last stick wins. For each heap size $1 \dots n$, classify the position as winning (`W`) or losing (`L`) for the first player.

## Input
The first line has $n$ and $k$. The next line lists the $k$ distinct allowed moves $p_i$ (one of them is $1$).

## Output
Print a string of $n$ characters, `W` for winning and `L` for losing positions.

## Constraints
- $1 \le n \le 10^6$
- $1 \le k \le 100$
- $1 \le p_i \le n$
