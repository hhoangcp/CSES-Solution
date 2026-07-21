# Range Xor Queries - Solution

**ID:** 1650 | **URL:** https://cses.fi/problemset/task/1650

## Approach

### Problem Restatement

Given a static array of $n$ integers, process $q$ queries each asking for the XOR of elements in range $[a, b]$.

### Core idea

Use **prefix XOR**, analogous to prefix sums. Build array $S$ with $S[0] = 0$ and $S[i] = S[i-1] \oplus x_i$. The XOR of range $[a, b]$ is:

$$x_a \oplus x_{a+1} \oplus \cdots \oplus x_b = S[b] \oplus S[a-1]$$

This works because XOR is self-inverse: $x \oplus x = 0$ and $x \oplus 0 = x$. The elements $x_1, \ldots, x_{a-1}$ appear in both $S[b]$ and $S[a-1]$, so they cancel out:

$$S[b] \oplus S[a-1] = (x_1 \oplus \cdots \oplus x_{a-1} \oplus x_a \oplus \cdots \oplus x_b) \oplus (x_1 \oplus \cdots \oplus x_{a-1}) = x_a \oplus \cdots \oplus x_b$$

This is the XOR analogue of prefix sums for range sum queries, exploiting $x \oplus x = 0$ instead of $x + (-x) = 0$.

### Algorithm

1. Build prefix XOR array: $S[0] = 0$, $S[i] = S[i-1] \oplus x_i$ for $i = 1, \ldots, n$.
2. For each query on range $[a, b]$, output $S[b] \oplus S[a-1]$.

### Example

Input:
```
8 4
3 2 4 5 1 1 5 3
2 4
5 6
1 8
3 3
```

Array: $[3, 2, 4, 5, 1, 1, 5, 3]$. Prefix XOR: $S = [0, 3, 1, 5, 0, 1, 0, 5, 6]$.

- Query $[2, 4]$: $S[4] \oplus S[1] = 0 \oplus 3 = 3$. Check: $2 \oplus 4 \oplus 5 = 3$.
- Query $[5, 6]$: $S[6] \oplus S[4] = 0 \oplus 0 = 0$. Check: $1 \oplus 1 = 0$.
- Query $[1, 8]$: $S[8] \oplus S[0] = 6 \oplus 0 = 6$.
- Query $[3, 3]$: $S[3] \oplus S[2] = 5 \oplus 1 = 4$.

Output:
```
3
0
6
4
```

## Complexity

- **Time:** $O(n + q)$
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Range%20Xor%20Queries.cpp)
