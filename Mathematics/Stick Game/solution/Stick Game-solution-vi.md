# Stick Game - Lời giải

**ID:** 1729 | **URL:** https://cses.fi/problemset/task/1729

## Phương pháp

### Tóm tắt bài toán

Trò chơi hai người luân phiên lấy que từ một đống. Tập nước đi $P = \{p_1, p_2, \ldots, p_k\}$ xác định số que được lấy mỗi lượt. Người lấy que cuối cùng thắng. Với mỗi số que từ $1$ đến $n$, xác định vị thế thắng (W) hay thua (L).

### Ý tưởng chính

Theo lý thuyết trò chơi tổ hợp trung lập:
- **Vị thế thua (L):** Mọi nước đi đều dẫn đến vị thế thắng cho đối thủ.
- **Vị thế thắng (W):** Tồn tại ít nhất một nước đi dẫn đến vị thế thua cho đối thủ.

Gọi $dp[i]$ = true nếu $i$ que là vị thế thắng. Công thức chuyển:

$$dp[i] = \bigvee_{j : p_j \le i} \neg dp[i - p_j]$$

Cơ sở: $dp[0] = \text{false}$ (0 que, không có nước đi, người đến lượt thua).

**Chứng minh quy nạp:** Cơ sở $i=0$: không có nước đi, người chơi thua. Bước quy nạp: nếu $dp[i] = \text{true}$, tồn tại $p_j$ cho $dp[i-p_j] = \text{false}$, người chơi hiện tại di chuyển đến vị thế thua của đối thủ. Nếu $dp[i] = \text{false}$, mọi $dp[i-p_j] = \text{true}$, mọi nước đi đều để đối thủ ở vị thế thắng.

### Thuật toán

1. Đặt $dp[0] = \text{false}$.
2. Với $i = 1, \ldots, n$: $dp[i] = \text{true}$ nếu tồn tại $p_j \le i$ với $dp[i - p_j] = \text{false}$.
3. Xuất 'W' nếu $dp[i] = \text{true}$, 'L' nếu ngược lại.

### Ví dụ minh họa

$n = 10$, $P = \{1, 3, 4\}$.

| $i$ | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 |
|-----|---|---|---|---|---|---|---|---|---|---|---|
| $dp$ | L | W | L | W | W | W | W | L | W | L | W |

- $dp[1]$: lấy 1 $\to$ $dp[0] = L$ → W
- $dp[2]$: chỉ lấy 1 $\to$ $dp[1] = W$ → L
- $dp[7]$: lấy 1 $\to$ $dp[6]=W$, lấy 3 $\to$ $dp[4]=W$, lấy 4 $\to$ $dp[3]=W$ → L

Kết quả: `WLWWWWLWLW` $\checkmark$

## Độ phức tạp

- **Thời gian:** $O(n \cdot k)$
- **Không gian:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Stick%20Game.cpp)
