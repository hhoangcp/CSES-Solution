# Creating Strings - Solution

**ID:** 1622 | **URL:** https://cses.fi/problemset/task/1622

## Approach

### Problem Restatement

Given a string of length $n$ ($1 \le n \le 8$), generate all distinct permutations in lexicographic order and count them.

### Core Idea

**Counting formula:** If the string has $k$ distinct characters with frequencies $c_1, c_2, \ldots, c_k$, the number of distinct permutations is $\frac{n!}{c_1! \cdot c_2! \cdot \ldots \cdot c_k!}$. This is because $n!$ counts all arrangements, but permuting identical characters among themselves ($c_i!$ ways each) doesn't produce a new string.

**Generation via `std::next_permutation`:** Starting from the lexicographically smallest permutation (obtained by sorting), repeatedly call `next_permutation` to produce the next strictly greater permutation. The function works by: (1) finding the last ascending pair from the right, (2) swapping with the smallest greater element to the right, (3) reversing the suffix. This naturally skips duplicates — swapping two identical characters yields the same string, so no duplicate permutation is ever generated.

**Correctness:** Starting from the smallest permutation and generating each strictly greater one ensures all distinct permutations are produced in lexicographic order, with no gaps and no repetitions, until the largest permutation is reached.

### Algorithm

1. Sort the string lexicographically.
2. Store the sorted string as the first permutation.
3. While `next_permutation` returns `true`, store each new permutation.
4. Output the count and all stored permutations.

### Example

Input: `aabac` ($n=5$, frequencies: a=3, b=1, c=1). Number of distinct permutations: $\frac{5!}{3! \cdot 1! \cdot 1!} = 20$. The 20 permutations start from `aaabc` and end at `cbaaa`.

## Complexity

- **Time:** $O(P \cdot n)$, where $P$ is the number of distinct permutations (at most $n!$)
- **Space:** $O(P \cdot n)$

## Code (C++)

[Solution Code](../code/Creating%20Strings.cpp)
