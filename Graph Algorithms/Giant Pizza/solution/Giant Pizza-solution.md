# Giant Pizza - Solution

**ID:** 1684 | **URL:** https://cses.fi/problemset/task/1684

## Approach

### Problem Restatement

There are $n$ family members and $m$ possible toppings. Each member gives two wishes of the form "+x" (topping $x$ is good) or "-x" (topping $x$ is bad). Choose toppings so that at least one wish from every member is satisfied. If impossible, print "IMPOSSIBLE".

### Core Idea

Model as **2-SAT**: each topping $i$ is a boolean variable ($x_i = $ true means include it). Each member gives a clause $(a \lor b)$. The clause $(a \lor b)$ is equivalent to two implications: $\neg a \implies b$ and $\neg b \implies a$.

Build an **implication graph** with $2m$ vertices: vertex $i$ for $x_i = \text{true}$, vertex $i + m$ for $\neg x_i$. For each clause, add the two implication edges.

Use **Kosaraju's algorithm** to find all SCCs. The 2-SAT formula is satisfiable if and only if no variable has $x_i$ and $\neg x_i$ in the same SCC. If $x_i$ and $\neg x_i$ are in the same SCC, then $x_i \implies \neg x_i$ and $\neg x_i \implies x_i$, yielding the contradiction $x_i \iff \neg x_i$.

If satisfiable, assign values by comparing SCC indices: $x_i = \text{true}$ if $\text{scc}[i] > \text{scc}[i+m]$, otherwise $x_i = \text{false}$. This works because Kosaraju processes SCCs in reverse topological order — if $\text{scc}[x_i] > \text{scc}[\neg x_i]$, then $\neg x_i$'s SCC was processed first, meaning no implication forces $x_i$ to be false. Any implication $x_i \implies \neg x_i$ would put $\neg x_i$ in the same or later SCC, contradicting $\text{scc}[x_i] > \text{scc}[\neg x_i]$.

### Algorithm

1. **Build implication graph:** For each clause $(a \lor b)$, add edges $\neg a \to b$ and $\neg b \to a$. Vertex $i$ represents $x_i$; vertex $i + m$ represents $\neg x_i$. Negation: vertex $j$ maps to $j + m$ if $j \leq m$, else $j - m$.
2. **Kosaraju:** DFS on original graph, record completion order. DFS on transposed graph in reverse completion order — each DFS tree is one SCC.
3. **Check:** If $\text{scc}[i] = \text{scc}[i+m]$ for any $i$, output "IMPOSSIBLE".
4. **Assign:** For each topping $i$: if $\text{scc}[i] > \text{scc}[i+m]$, output "+"; otherwise output "-".

### Example

Input:
```
3 5
+ 1 + 2
- 1 + 3
+ 4 - 2
```

3 members, 5 toppings. Clauses: $x_1 \lor x_2$, $\neg x_1 \lor x_3$, $x_4 \lor \neg x_2$.

Implication edges (10 vertices: 1–5 for true, 6–10 for false):
- Clause 1: $\neg x_1 \to x_2$ (6→2), $\neg x_2 \to x_1$ (7→1)
- Clause 2: $x_1 \to x_3$ (1→3), $\neg x_3 \to \neg x_1$ (8→6)
- Clause 3: $\neg x_4 \to \neg x_2$ (9→7), $x_2 \to x_4$ (2→4)

Kosaraju finds no variable with $x_i$ and $\neg x_i$ in the same SCC. Assignment: e.g., scc[1] < scc[6] → $x_1 = -$; scc[2] > scc[7] → $x_2 = +$; scc[3] > scc[8] → $x_3 = +$; scc[4] > scc[9] → $x_4 = +$; scc[5] < scc[10] → $x_5 = -$.

Output:
```
- + + + -
```

Verify: member 1 (+1 or +2) = (F or T) ✓; member 2 (-1 or +3) = (T or T) ✓; member 3 (+4 or -2) = (T or F) ✓.

## Complexity

- **Time:** $O(n + m)$ — two DFS passes on a graph with $2m$ vertices and $2n$ edges.
- **Space:** $O(n + m)$

## Code (C++)

[Solution Code](../code/Giant%20Pizza.cpp)
