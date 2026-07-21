# Edit Distance - Lời giải

**ID:** 1639 | **URL:** https://cses.fi/problemset/task/1639

## Hướng tiếp cận

### Tóm tắt bài toán

Cho hai xâu $S$ và $T$ độ dài $n$ và $m$, tìm số phép toán ít nhất (chèn, xóa, thay thế một ký tự) để biến $S$ thành $T$.

### Ý tưởng chính

Gọi $dp[i][j]$ là khoảng cách chỉnh sửa giữa tiền tố $S[1..i]$ và $T[1..j]$. Xét phép toán cuối cùng ảnh hưởng đến vị trí $i$ của $S$ hoặc vị trí $j$ của $T$:

- **Khớp/Thay thế** tại $(i, j)$: chi phí $0$ nếu $S[i] = T[j]$, ngược lại $1$. Các phép toán trước biến $S[1..i{-}1]$ thành $T[1..j{-}1]$: $dp[i{-}1][j{-}1] + [S[i] \neq T[j]]$.
- **Xóa** $S[i]$: chi phí $1$. Các phép toán trước biến $S[1..i{-}1]$ thành $T[1..j]$: $dp[i{-}1][j] + 1$.
- **Chèn** $T[j]$: chi phí $1$. Các phép toán trước biến $S[1..i]$ thành $T[1..j{-}1]$: $dp[i][j{-}1] + 1$.

$$dp[i][j] = \min(dp[i{-}1][j{-}1] + [S[i] \neq T[j]], dp[i{-}1][j] + 1, dp[i][j{-}1] + 1)$$

Mọi dãy tối ưu phải kết thúc bằng một trong ba loại phép toán trên, nên min trên cả ba cho kết quả đúng — không bỏ sót. Mỗi phép toán dẫn đến bài toán con nhỏ hơn ($i{+}j$ giảm, hoặc $i$/$j$ giảm), nên quy nạp được áp dụng — không đếm dư.

Trường hợp cơ sở: $dp[0][j] = j$ (chèn $j$ ký tự) và $dp[i][0] = i$ (xóa $i$ ký tự).

### Thuật toán

1. Khởi tạo $dp[0][j] = j$ với $j = 0 \ldots m$.
2. Với $i = 1$ đến $n$:
   - Đặt $dp[i][0] = i$.
   - Với $j = 1$ đến $m$: $dp[i][j] = \min(dp[i{-}1][j{-}1] + [S[i] \neq T[j]], dp[i{-}1][j] + 1, dp[i][j{-}1] + 1)$.
3. Kết quả là $dp[n][m]$.

Dùng mảng cuộn hai hàng vì mỗi hàng chỉ phụ thuộc hàng trước.

### Ví dụ minh họa

Input: $S = \text{LOVE}$, $T = \text{MOVIE}$.

| | | M | O | V | I | E |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| | 0 | 1 | 2 | 3 | 4 | 5 |
| **L** | 1 | 1 | 2 | 3 | 4 | 5 |
| **O** | 2 | 2 | 1 | 2 | 3 | 4 |
| **V** | 3 | 3 | 2 | 1 | 2 | 3 |
| **E** | 4 | 4 | 3 | 2 | 2 | 2 |

Kết quả: $dp[4][5] = 2$ — thay L→M, chèn I.

## Độ phức tạp

- **Thời gian:** $O(n \cdot m)$
- **Không gian:** $O(m)$

## Mã nguồn (C++)

[Mã nguồn](../code/Edit%20Distance.cpp)
