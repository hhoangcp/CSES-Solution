# Raab Game I

**CSES ID:** 3399  
**Full statement:** https://cses.fi/problemset/task/3399  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Two players each hold cards numbered $1$ to $n$; on each round they reveal one card and the higher card wins a point (ties score nothing). Given $n$ and final scores $a$ and $b$, decide whether such a game is possible and, if so, exhibit the two players' card orders producing those scores.

## Input
First line: integer $t$. Then $t$ lines each with three integers $n$, $a$, $b$.

## Output
For each test print `YES`/`NO`. When `YES`, also print two lines giving each player's card sequence. Any valid example is accepted.

## Constraints
- $1 \le t \le 1000$
- $1 \le n \le 100$
- $0 \le a, b \le n$
