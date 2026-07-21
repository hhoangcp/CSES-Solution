# Another Game

**CSES ID:** 2208  
**Full statement:** https://cses.fi/problemset/task/2208  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

A two-player impartial game is played on $n$ heaps of coins. A move consists of choosing any nonempty subset of heaps and removing exactly one coin from each chosen heap; whoever takes the last coin wins. Determine the winner assuming optimal play.

## Input
The first line gives the number of test cases $t$. Each test starts with $n$, followed by a line of $n$ heap sizes.

## Output
For each test print `first` or `second` depending on who wins under optimal play.

## Constraints
- $1 \le t \le 2 \cdot 10^5$
- $1 \le n \le 2 \cdot 10^5$
- $1 \le x_i \le 10^9$
- $\sum n \le 2 \cdot 10^5$
