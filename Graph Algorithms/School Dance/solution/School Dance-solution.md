# School Dance - Solution

**ID:** 1696 | **URL:** https://cses.fi/problemset/task/1696

## Approach

### Problem Restatement

Given a bipartite graph with $n$ boys, $m$ girls, and $k$ potential pairs (edges), find a maximum matching — the largest set of edges where no two edges share a vertex — and output the matched pairs.

### Core Idea

Model the problem as **maximum bipartite matching** and solve it using **Kuhn's algorithm** (augmenting path algorithm).

An **augmenting path** is a path that starts from an unmatched boy, alternates between non-matching and matching edges, and ends at an unmatched girl. Flipping the status of all edges along an augmenting path (non-matching ↔ matching) increases the matching size by exactly 1, since the path has odd length with one more non-matching edge than matching edge.

**Berge's Theorem:** A matching is maximum if and only if no augmenting path exists with respect to it. Therefore, repeatedly finding and flipping augmenting paths until none exist produces a maximum matching.

To find an augmenting path from an unmatched boy $u$, use DFS: for each girl $v$ adjacent to $u$, if $v$ is unmatched, the path is complete; if $v$ is matched with some boy $u'$, recursively try to find an alternative match for $u'$. If successful, $u'$ is rematched elsewhere, freeing $v$ for $u$.

**Correctness.** Each augmenting path flip increases the matching size by exactly 1 (the path has $2k+1$ edges: $k$ matching and $k+1$ non-matching; after flipping, $k+1$ matching and $k$ non-matching). By Berge's theorem, when no augmenting path exists, the matching is maximum. The algorithm terminates because the matching size is bounded by $\min(n, m)$ and increases each iteration.

### Algorithm

1. Start with an empty matching ($\text{match}[v] = 0$ for all girls $v$).
2. For each boy $u$ from 1 to $n$:
   - Reset the `visited` array for girls.
   - Call DFS to find an augmenting path from $u$. If found, update the matching and increment the count.
3. Output the number of matched pairs and each pair $(\text{match}[v], v)$.

### Example

Input:
```
3 2 4
1 1
1 2
2 1
3 1
```

Edges: boy 1 → [girl 1, girl 2], boy 2 → [girl 1], boy 3 → [girl 1].

- Boy 1: DFS finds girl 1 (unmatched) → match[1] = 1.
- Boy 2: DFS tries girl 1 (matched with boy 1) → recursively find alternative for boy 1 → boy 1 finds girl 2 (unmatched) → rematch: match[2] = 1, match[1] = 2.
- Boy 3: DFS tries girl 1 (matched with boy 2) → recursively find alternative for boy 2 → boy 2 has no other neighbor → fails.

Result: 2 pairs — $(1, 2)$ and $(2, 1)$.

Output:
```
2
1 2
2 1
```

(The problem accepts any valid matching. The sample output `1 2, 3 1` is also correct.)

## Complexity

- **Time:** $O(n \cdot k)$ — each DFS takes $O(k)$, called at most $O(n)$ times (each successful call increases the matching, and there are at most $\min(n, m)$ successful calls).
- **Space:** $O(n + m + k)$ — adjacency list, matching array, and visited array.

## Code (C++)

[Solution Code](../code/School%20Dance.cpp)
