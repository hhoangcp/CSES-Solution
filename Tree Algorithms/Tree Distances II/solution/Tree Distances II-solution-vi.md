# Tree Distances II - Lời giải

**ID:** 1133 | **URL:** https://cses.fi/problemset/task/1133

## Phương pháp

### Tóm tắt bài toán

Cho một cây gồm $n$ đỉnh. Tính với mỗi đỉnh tổng khoảng cách từ nó đến tất cả các đỉnh còn lại.

**Ràng buộc:** $1 \le n \le 2 \cdot 10^5$.

### Ý tưởng chính

Dùng quy hoạch động chuyển gốc (rerooting DP) qua hai lần DFS.

**DFS lần 1 (tính tại gốc tạm $1$):** Với mỗi $u$, tính:

- $sz[u] = 1 + \sum_{v \in \text{con}(u)} sz[v]$ — số đỉnh trong cây con gốc $u$.
- $dp[u] = \sum_{v \in \text{con}(u)} (dp[v] + sz[v])$ — tổng khoảng cách từ $u$ đến mọi đỉnh trong cây con $u$.

Giải thích $dp[u]$: với mỗi con $v$, mỗi đỉnh $w$ trong cây con $v$ có $d(u, w) = d(v, w) + 1$, nên đóng góp của cây con $v$ vào $dp[u]$ là $dp[v] + sz[v]$.

**DFS lần 2 (chuyển gốc):** Khi chuyển gốc từ $u$ sang con $v$ (khiến $v$ thành gốc mới của toàn cây), khoảng cách từ $v$ đến mỗi đỉnh trong cây con $v$ (theo gốc $1$) **giảm $1$**, và đến mỗi đỉnh ngoài cây con $v$ **tăng $1$**. Do đó:

$$ans[v] = ans[u] - sz[v] + (n - sz[v])$$

trong đó $sz[v]$ là kích thước cây con $v$ tính theo gốc $1$ (giá trị gốc, không đổi). Tại mỗi $u$, ghi $ans[u]$ rồi áp dụng công thức để tính cho các con.

**Tính đúng đắn:** Bổ đề 1 (quy nạp): $dp[u]$ đúng bằng tổng khoảng cách trong cây con $u$ — vì mỗi đỉnh $w$ trong cây con con $v$ có $d(u,w)=d(v,w)+1$, tổng đóng góp đúng $dp[v]+sz[v]$. Bổ đề 2: khi chuyển gốc $u \to v$, đúng $sz[v]$ đỉnh (trong cây con $v$) gần đi $1$ và $n - sz[v]$ đỉnh (ngoài) xa đi $1$, nên tổng thay đổi đúng $-sz[v] + (n - sz[v])$. Vậy $ans[v]$ tính bằng công thức trên là tổng khoảng cách từ $v$ tới mọi đỉnh trong cây.

### Thuật toán

1. Đọc $n$; dựng danh sách kề từ $n-1$ cạnh.
2. `DFS(u)` (dùng `lab` để không quay lên cha): $dp[u] = 0, sz[u] = 1$; với mỗi con $v$ (`lab[u] != v`): $lab[v] = u$, `DFS(v)`, $dp[u] \mathrel{+}= dp[v] + sz[v]$, $sz[u] \mathrel{+}= sz[v]$.
3. `Rotate(u)`: $ans[u] = dp[u]$; với mỗi con $v$ (`lab[u] != v`), mô phỏng chuyển gốc bằng cách tạm điều chỉnh rồi khôi phục:
   - Bỏ $v$ khỏi $u$: $dp[u] \mathrel{-}= dp[v] + sz[v]$; $sz[u] \mathrel{-}= sz[v]$ (lúc này $sz[u] = n - sz[v]$, $dp[u]$ = tổng khoảng cách từ $u$ tới các đỉnh ngoài cây con $v$).
   - Đưa $u$ (mới) vào $v$: $sz[v] \mathrel{+}= sz[u]$; $dp[v] \mathrel{+}= dp[u] + sz[u]$ (mỗi đỉnh ngoài cây con $v$ xa $v$ thêm $1$ so với $u$).
   - Gọi `Rotate(v)`.
   - Khôi phục: $sz[v] \mathrel{-}= sz[u]$; $dp[v] \mathrel{-}= dp[u] + sz[u]$; $dp[u] \mathrel{+}= dp[v] + sz[v]$; $sz[u] \mathrel{+}= sz[v]$.
4. Gọi `DFS(1)`, rồi `Rotate(1)`; in $ans[1..n]$.

### Ví dụ minh họa

Đề bài cho $n = 5$, cạnh `1-2, 1-3, 3-4, 3-5`. Cây: $1 \to \{2, 3\}$; $3 \to \{4, 5\}$.

**DFS lần 1 (gốc $1$)** — tính $sz$ và $dp$:

| $u$ | $1$ | $2$ | $3$ | $4$ | $5$ |
|---|---|---|---|---|---|
| $sz[u]$ | $5$ | $1$ | $3$ | $1$ | $1$ |
| $dp[u]$ | $6$ | $0$ | $2$ | $0$ | $0$ |

Kiểm tra $dp[1] = (dp[2]+sz[2]) + (dp[3]+sz[3]) = (0+1) + (2+3) = 6$ $= 0+1+1+2+2$. ✓

**DFS lần 2 (chuyển gốc)** — áp dụng $ans[v] = ans[u] - sz[v] + (n - sz[v])$:

| Bước | $u$ | $v$ | $sz[v]$ | $ans[v] = ans[u] - sz[v] + (5 - sz[v])$ |
|---|---|---|---|---|
| gốc | — | $1$ | — | $ans[1] = dp[1] = 6$ |
| $1 \to 2$ | $1$ | $2$ | $1$ | $6 - 1 + 4 = 9$ |
| $1 \to 3$ | $1$ | $3$ | $3$ | $6 - 3 + 2 = 5$ |
| $3 \to 4$ | $3$ | $4$ | $1$ | $5 - 1 + 4 = 8$ |
| $3 \to 5$ | $3$ | $5$ | $1$ | $5 - 1 + 4 = 8$ |

Kết quả theo thứ tự đỉnh $1..5$: `6 9 5 8 8` — khớp với ví dụ đề bài.

## Độ phức tạp

- **Thời gian:** $O(n)$ — hai lần DFS, mỗi lần thăm hết các đỉnh và cạnh đúng một lần.
- **Bộ nhớ:** $O(n)$ — danh sách kề và các mảng $sz$, $dp$, $ans$, $lab$.

## Mã nguồn (C++)

[Mã nguồn](../code/Tree%20Distances%20II.cpp)
