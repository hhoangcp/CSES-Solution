# Coin Piles

**CSES ID:** 1754  
**Full statement:** https://cses.fi/problemset/task/1754  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Two piles hold $a$ and $b$ coins. Each move removes either $(1,2)$ or $(2,1)$ coins from the piles. For each query decide whether both piles can be emptied.

## Input
First line: integer $t$. Then $t$ lines, each with two integers $a$ and $b$.

## Output
For each query print `YES` if both piles can be emptied, otherwise `NO`.

## Constraints
- $1 \le t \le 10^5$
- $0 \le a, b \le 10^9$
