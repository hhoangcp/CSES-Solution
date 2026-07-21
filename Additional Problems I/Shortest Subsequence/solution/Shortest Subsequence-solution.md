# Shortest Subsequence - Solution

**ID:** 1087 | **URL:** https://cses.fi/problemset/task/1087

## Problem Statement

Given a DNA string consisting of characters `A`, `C`, `G`, `T`, find the shortest DNA string that is **NOT** a subsequence of the given string. A string $t$ is a subsequence of $s$ if $t$ can be obtained by deleting some characters from $s$.

## Approach

### 1. Idea: Complete Cover of 4 characters

Scan the DNA string from left to right and divide it into segments such that each segment contains at least one occurrence of all 4 characters `A`, `C`, `G`, `T`.

- Each time all 4 characters have been collected, we call this a **"complete cover"**.
- After completing a cover, we start counting fresh for the next cover.

### 2. Construct the missing string

Suppose we find $k$ complete covers.

- **Length:** Every string of length $\le k$ is guaranteed to be a subsequence of the original string. Therefore, the shortest non-subsequence must have length **$k + 1$**.
- **Character selection:**
  1. For each complete cover, take the **last character** (the character that completed the set of 4) and add it to the result string.
  2. After exhausting all complete covers, there remains a final incomplete segment. Choose a **missing character** from this segment and append it to the result.

### 3. Proof of correctness

- **Why is every string of length $k$ always a subsequence?** Since each cover contains all 4 characters, for any character in a string of length $k$, we can always find it in the corresponding cover.
- **Why is the constructed string of length $k+1$ NOT a subsequence?** By choosing the last character of each cover, we "force" the search to go through an entire cover before finding the next character. After $k$ covers, we choose a character that does not appear in the remaining portion, causing the search to fail.

## Example

String: `ACGTACGT`, $n=8$.

1. **Cover 1:** `A`, `C`, `G`, `T` (completed at position 4, character `T`).
2. **Cover 2:** `A`, `C`, `G`, `T` (completed at position 8, character `T`).
3. **Remainder:** After position 8 is empty, all 4 characters are missing. Choose `A`.

- **Result:** `TTA` (or `AAA`, `CCG`, etc., depending on which missing character you choose).

## Complexity

- **Time:** $O(n)$ — Only a single scan of the string is needed.
- **Memory:** $O(n)$ — For storing the input DNA string.

## Code (C++)

[Solution Code](../code/Shortest%20Subsequence.cpp)
