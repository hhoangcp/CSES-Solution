# Stack Weights - Solution

**ID:** 2425 | **URL:** https://cses.fi/problemset/task/2425

## Problem Statement

There are $n$ coins with strictly increasing weights ($w_1 < w_2 < \cdots < w_n$). Two stacks start empty. After each turn of placing a coin into a stack, determine which stack is definitely heavier, or if it is uncertain.

## Approach

### Abel transform and suffix sums

Assign $val_i = +1$ if coin $i$ goes to stack 1, $val_i = -1$ if stack 2. The weight difference is:

$$D = \sum_{i=1}^{n} val_i \cdot w_i$$

Let $suffix_k = \sum_{i=k}^{n} val_i$. By Abel summation:

$$D = \sum_{k=1}^{n} suffix_k \cdot (w_k - w_{k-1})$$

with $w_0 = 0$. Since $w_k - w_{k-1} > 0$ for all $k$, every term in the sum is a product of $suffix_k$ and a positive coefficient.

**Conclusion:**
- Stack 1 is definitely heavier ($D > 0$) $\iff$ all $suffix_k \geq 0$ (and at least one $> 0$).
- Stack 2 is definitely heavier ($D < 0$) $\iff$ all $suffix_k \leq 0$ (and at least one $< 0$).
- Otherwise: `?`.

**Necessary condition proof:** If $suffix_{k_0} < 0$ for some $k_0$, choose $w_{k_0} \gg$ all other weights. The term $suffix_{k_0} \cdot (w_{k_0} - w_{k_0-1})$ dominates and makes $D < 0$, so stack 1 is not definitely heavier.

### Segment tree with lazy propagation

When coin $c$ is placed into stack $s$, all $suffix_k$ for $k \leq c$ change by $\pm 1$. Use a segment tree with range-add and range-min query:

- **Stack_1 tree:** stores $suffix_k$. On coin $c$ into stack 1: add $+1$ to $[1, c]$; stack 2: add $-1$.
- **Stack_2 tree:** stores $-suffix_k$. On coin $c$ into stack 1: add $-1$ to $[1, c]$; stack 2: add $+1$.

After each turn:
- If $\min(\text{Stack\_1}) \geq 0$: output `>`
- Else if $\min(\text{Stack\_2}) \geq 0$: output `<`
- Else: output `?`

### Example

$n = 3$, $w_1 < w_2 < w_3$.

| Turn | Action | $val$ | $suffix$ | Stack_1 min | Stack_2 min | Output |
|------|--------|-------|----------|-------------|-------------|--------|
| 1 | Coin 2 → Stack 1 | [0,+1,0] | [1,1,0] | 0 | -1 | `>` |
| 2 | Coin 3 → Stack 2 | [0,+1,-1] | [0,0,-1] | -1 | 0 | `<` |
| 3 | Coin 1 → Stack 1 | [+1,+1,-1] | [1,0,-1] | -1 | -1 | `?` |

Verification: Turn 2 has stack 1 = {coin 2}, stack 2 = {coin 3}. Since $w_3 > w_2$, stack 2 is definitely heavier. Turn 3: stack 1 = {1,2}, stack 2 = {3}. Since $w_1 + w_2$ vs $w_3$ is unknown, result is `?`.

## Complexity

- **Time:** $O(n \log n)$ — $n$ range-updates and min-queries on segment tree
- **Memory:** $O(n)$

## Code (C++)

[Solution Code](../code/Stack%20Weights.cpp)
