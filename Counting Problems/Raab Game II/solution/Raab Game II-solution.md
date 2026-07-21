# Raab Game II - Solution

**ID:** 3400 | **URL:** https://cses.fi/problemset/task/3400

## Approach

### Problem Restatement

Two players each hold cards $\{1, \ldots, n\}$. Each round, both play one card; the higher card scores a point, equal cards score nothing. For each query $(n, a, b)$, count the number of games ending with player 1 winning $a$ times and player 2 winning $b$ times. Result modulo $10^9 + 7$.

### DP on win counts

Define $\text{dp}[i][j]$ = number of ways to construct a sequence of decisive rounds (non-tie rounds) where player 1 wins $i$ times and player 2 wins $j$ times. The key is tracking how new decisive rounds interact with existing ones.

After $i + j$ decisive rounds, each round has one winner. To add a new decisive round, we insert it among the existing rounds. The multiplicative coefficients come from counting available "slots":

- **P1 wins new round ($\text{dp}[i{+}1][j] \mathrel{+}= \text{dp}[i][j] \cdot j$):** P1's new card must beat P2's card. We pair P1's new card with a previously "losing" P2 card — one from a round where P2 won (there are $j$ such rounds). So there are $j$ choices for which P2 card to beat.

- **P2 wins new round ($\text{dp}[i][j{+}1] \mathrel{+}= \text{dp}[i][j] \cdot i$):** Symmetrically, P2's new card beats one of $i$ previously "losing" P1 cards.

- **Both win simultaneously ($\text{dp}[i{+}1][j{+}1] \mathrel{+}= \text{dp}[i][j] \cdot (i{+}j{+}1)$):** Insert a new decisive round where P1 and P2 both use fresh cards. The new round can be placed in any of $i + j + 1$ slots (before round 1, between any two consecutive rounds, or after the last round).

### Impossible cases

- **$a + b > n$:** More decisive rounds than cards available. Result = 0.
- **$\min(a, b) = 0$ and $\max(a, b) > 0$:** If one player wins at least once, the loser of that round must also have won some round (to maintain the cyclic structure of card values — each decisive round pairs a higher and lower card, and these must be balanced). Equivalently, each win for P1 consumes a "slot" created by P2's wins and vice versa. Result = 0.

### Final formula

$$\text{ans}(a, b) = \text{dp}[a][b] \cdot \binom{n}{a+b} \cdot n!$$

- **$\text{dp}[a][b]$:** Number of ways to structure the win/loss relationships among decisive rounds.
- **$\binom{n}{a+b}$:** Choose which $a + b$ of the $n$ rounds are decisive (non-tie). The remaining $n - a - b$ rounds are ties.
- **$n!$:** Assign actual card values. Once P1's deck is fixed (a permutation of $\{1, \ldots, n\}$), P2's deck is uniquely determined by the win/loss structure — each of P2's cards must be either higher or lower than P1's corresponding card, as specified by the DP structure.

### Example

**Problem examples:**

$n = 3$, $a = 1$, $b = 2$: $\text{dp}[1][2] = 1$. Result: $1 \cdot \binom{3}{3} \cdot 6 = 6$. ✓

$n = 2$, $a = 0$, $b = 1$: $\min = 0$, $\max > 0$ → **0**. ✓

$n = 5$, $a = 2$, $b = 2$: $\text{dp}[2][2] = 7$. Result: $7 \cdot \binom{5}{4} \cdot 120 = 7 \cdot 5 \cdot 120 = 4200$. ✓

$n = 4$, $a = 4$, $b = 1$: $a + b = 5 > 4 = n$ → **0**. ✓

**DP trace** for small values (from $\text{dp}[0][0] = 1$):

| $(i,j)$ | value | transitions |
|---------|-------|-------------|
| (0,0) | 1 | → (1,1): $1 \cdot 1 = 1$ |
| (1,1) | 1 | → (2,1): $1$, (1,2): $1$, (2,2): $3$ |
| (2,1) | 1 | → (3,1): $1$, (2,2): $+2$, (3,2): $4$ |
| (1,2) | 1 | → (2,2): $+2$, (1,3): $1$, (2,3): $4$ |

$\text{dp}[2][2] = 3 + 2 + 2 = 7$. ✓

## Complexity

- **Time:** $O(n^2)$ precomputation, $O(1)$ per query.
- **Space:** $O(n^2)$ for the DP table.

## Code (C++)

[Solution Code](../code/Raab%20Game%20II.cpp)
