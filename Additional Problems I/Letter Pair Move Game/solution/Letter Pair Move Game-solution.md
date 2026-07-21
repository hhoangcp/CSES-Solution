# Letter Pair Move Game - Solution

**ID:** 2427 | **URL:** https://cses.fi/problemset/task/2427

## Problem Statement

There are $2n$ boxes arranged in a row, with $2$ adjacent empty cells (denoted `..`) and $2n-2$ boxes containing letters 'A' or 'B' ($n-1$ of each). Each turn, you select an adjacent pair of letters and move them into the current empty positions without changing the order of the pair. The goal is to place all 'A's before all 'B's in at most $1000$ turns.

## Approach

### 1. Check target state

A state is considered complete when every letter 'A' lies to the left of every letter 'B'. The position of the two empty cells can be anywhere in the array.

### 2. Greedy strategy

The algorithm searches for letter pairs to move into the empty positions based on priority rules aimed at pushing 'A's leftward and 'B's rightward:

- **Priority 1:** Find a `BA` or `BB` pair to the **left** of the empty cells. Moving them into the empty cells helps push 'B' characters toward the right.
- **Priority 2:** Find an `AB` or `AA` pair to the **right** of the empty cells. Moving them into the empty cells helps pull 'A' characters toward the left.
- **Deadlock handling:** If none of the above pairs are found, find a `BA` pair to the right of the empty cells, move it into the empty cells to change the array structure, then restart the search from the beginning.

### 3. Proof of correctness and impossibility condition

- **Parity invariant:** Let $P$ be the number of 'A's to the left of the empty cells. When moving an adjacent pair of letters:
  - Moving pair `AA`: $P$ changes by $2$ (increases or decreases).
  - Moving pair `BB`: $P$ is unchanged.
  - Moving pair `AB` or `BA`: $P$ is unchanged.
  
  Therefore, **the parity of $P$ is invariant** throughout the process. If the initial state has $P \not\equiv n-1 \pmod 2$, the problem may have no solution.

- **Algorithm progress:** Each valid move is designed to reduce the number of inversion pairs `BA` or gradually move the array toward a converged state. The actual number of moves is typically very small, at most $5n$, well within the $1000$ limit of the problem.

## Example walkthrough

Array: `AB..BA`, $n=3$.

1. **Step 1:** Empty cells at positions 3-4. Find `BA` pair to the right (positions 5-6). Move `BA` into 3-4.
   - Result: `ABBA..`
2. **Step 2:** Empty cells at positions 5-6. Find `BB` pair to the left (positions 3-4). Move `BB` into 5-6.
   - Result: `A..ABB`
3. **Verification:** All 'A's are before 'B's. Completed in 2 steps.

## Complexity

- **Time:** $O(n^2)$ — At most $5n$ iterations, each scanning the $2n$ array to find a move pair.
- **Memory:** $O(n)$ — Storing the array state and move sequence.

## Code (C++)

[Solution Code](../code/Letter%20Pair%20Move%20Game.cpp)
