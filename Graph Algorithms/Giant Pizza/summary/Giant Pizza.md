# Giant Pizza

**CSES ID:** 1684  
**Full statement:** https://cses.fi/problemset/task/1684  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

There are $m$ pizza toppings and $n$ members, each giving two wishes of the form "topping $x$ is good" or "topping $x$ is bad". Choose which toppings to include so that each member has at least one satisfied wish.

## Input
$n$ and $m$, then $n$ lines each with two wishes `+ x` or `- x`.

## Output
A line of $m$ signs (`+`/`-`) telling whether each topping is included, or `IMPOSSIBLE`.

## Constraints
- $1 \le n,m \le 10^5$
- $1 \le x \le m$
