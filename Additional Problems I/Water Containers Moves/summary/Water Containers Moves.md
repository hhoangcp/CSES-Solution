# Water Containers Moves

**CSES ID:** 3213  
**Full statement:** https://cses.fi/problemset/task/3213  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Two containers of capacities $a$ and $b$ start empty. Allowed moves are filling, emptying, or pouring from one container to the other (which must fill or empty at least one). Produce a move sequence ending with exactly $x$ units in container $A$ that minimizes the total water moved, or report impossibility.

## Input
Three integers $a$, $b$, and $x$.

## Output
Print move count and total water moved, then the moves (`FILL A`, `FILL B`, `EMPTY A`, `EMPTY B`, `MOVE A B`, `MOVE B A`), or `-1`.

## Constraints
- $1 \le a, b, x \le 1000$
