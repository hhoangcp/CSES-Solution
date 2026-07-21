# Grid Path Construction

**CSES ID:** 2418  
**Full statement:** https://cses.fi/problemset/task/2418  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Given an $n \times m$ grid and two distinct cells $a=(y_1,x_1)$ and $b=(y_2,x_2)$, decide whether there is a path from $a$ to $b$ that visits every cell exactly once, moving only between orthogonal neighbors. When possible, output the path as a sequence of `U`/`D`/`L`/`R` moves.

## Input
First line: integer $t$. Then $t$ lines, each with six integers $n$, $m$, $y_1$, $x_1$, $y_2$, $x_2$.

## Output
For each test print `YES` and the move sequence when a path exists, otherwise `NO`.

## Constraints
- $1 \le t \le 100$
- $1 \le n \le 50$
- $1 \le m \le 50$
- $y_1 \neq y_2$ or $x_1 \neq x_2$
