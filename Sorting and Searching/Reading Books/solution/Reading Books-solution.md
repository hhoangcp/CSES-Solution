# Reading Books - Solution

**ID:** 1631 | **URL:** https://cses.fi/problemset/task/1631

## Approach

Let $\text{sum} = \sum_{i=1}^{n} t_i$ be the total reading time and $\text{mmax} = \max_i t_i$ be the longest book's reading time.

**Lower bounds:**

1. Each book must be read by both people, so the total time is at least $\text{sum}$.
2. While one person reads the longest book ($\text{mmax}$ minutes), the other can read the remaining books ($\text{sum} - \text{mmax}$ minutes total). If $\text{mmax} > \text{sum} - \text{mmax}$, the other person finishes early and must wait, then reads the longest book. The total time is at least $2 \cdot \text{mmax}$.

Therefore, the answer $\geq \max(\text{sum}, 2 \cdot \text{mmax})$.

**Achievability:**

- **Case $2 \cdot \text{mmax} \leq \text{sum}$:** No book dominates. Person A reads books left to right, person B reads right to left. Since the remaining books (excluding the longest) sum to $\geq \text{mmax}$, the two people never collide on the same book, and the total time equals $\text{sum}$.
- **Case $2 \cdot \text{mmax} > \text{sum}$:** Person A reads the longest book from $0$ to $\text{mmax}$. Person B reads all other books from $0$ to $\text{sum} - \text{mmax}$, waits, then reads the longest book from $\text{mmax}$ to $2 \cdot \text{mmax}$. Total time: $2 \cdot \text{mmax}$.

Answer: $\max(\text{sum}, 2 \cdot \text{mmax})$.

### Example

Consider $n = 3$, books $t = [2, 8, 3]$.

- $\text{sum} = 2 + 8 + 3 = 13$
- $\text{mmax} = 8$, $2 \cdot \text{mmax} = 16$
- Answer: $\max(13, 16) = 16$

Schedule: Person A reads the longest book (8) from minute 0 to 8. Person B reads books 2 and 3 from minute 0 to 5, then waits until minute 8 to read the longest book from 8 to 16. Both finish at minute 16.

## Complexity

- **Time:** $O(n)$ — single pass to compute $\text{sum}$ and $\text{mmax}$.
- **Memory:** $O(1)$ — only two variables needed.

## Code (C++)

[Solution Code](../code/Reading%20Books.cpp)
