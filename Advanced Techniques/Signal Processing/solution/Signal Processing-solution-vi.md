# Signal Processing - Lời giải

**ID:** 2113 | **URL:** https://cses.fi/problemset/task/2113

## Phương pháp

### Tóm tắt bài toán

Cho tín hiệu dài $n$ và mặt nạ dài $m$, tính tổng tích các giá trị căn chỉnh tại mỗi vị trí khi mặt nạ trượt qua tín hiệu. Xuất $n + m - 1$ giá trị.

### Ý tưởng chính

Tại mỗi vị trí, kết quả là $\sum_i A[i+k] \cdot B[i]$ trên các chỉ số hợp lệ — đây là **tương quan chéo**. Để tính nhanh bằng FFT, đảo mặt nạ: $B'[i] = B[m{-}1{-}i]$. Tích chập $C = A * B'$ cho:

$$C[k] = \sum_j A[j] \cdot B'[k-j] = \sum_j A[j] \cdot B[m{-}1{-}k{+}j]$$

Đổi biến $i = j - k + m - 1$, ta được $\sum_i A[i + k - m + 1] \cdot B[i]$, đúng bằng tổng tích căn chỉnh khi mặt nạ ở vị trí $k - m + 1$. Khi $k$ chạy từ 0 đến $n + m - 2$, bao phủ tất cả vị trí trượt hợp lệ.

### Thuật toán

1. Đọc tín hiệu $A$ và mặt nạ $B$. Đảo mặt nạ: $B'[i] = B[m{-}1{-}i]$.
2. Tính tích chập $C = A * B'$ bằng FFT (biến đổi xuôi cả hai, nhân điểm, biến đổi ngược).
3. Xuất $\text{round}(C[k])$ cho $k = 0, \ldots, n+m-2$.

### Ví dụ minh họa

Tín hiệu: $A = [1, 3, 2, 1, 4]$, Mặt nạ: $B = [1, 2, 3]$. Mặt nạ đảo: $B' = [3, 2, 1]$.

| $k$ | Cặp căn chỉnh | Tính | $C[k]$ |
|-----|---------------|------|--------|
| 0 | $A[0] \cdot B[2]$ | $1 \cdot 3$ | 3 |
| 1 | $A[0] \cdot B[1] + A[1] \cdot B[2]$ | $1 \cdot 2 + 3 \cdot 3$ | 11 |
| 2 | $A[0] \cdot B[0] + A[1] \cdot B[1] + A[2] \cdot B[2]$ | $1 \cdot 1 + 3 \cdot 2 + 2 \cdot 3$ | 13 |
| 3 | $A[1] \cdot B[0] + A[2] \cdot B[1] + A[3] \cdot B[2]$ | $3 \cdot 1 + 2 \cdot 2 + 1 \cdot 3$ | 10 |
| 4 | $A[2] \cdot B[0] + A[3] \cdot B[1] + A[4] \cdot B[2]$ | $2 \cdot 1 + 1 \cdot 2 + 4 \cdot 3$ | 16 |
| 5 | $A[3] \cdot B[0] + A[4] \cdot B[1]$ | $1 \cdot 1 + 4 \cdot 2$ | 9 |
| 6 | $A[4] \cdot B[0]$ | $4 \cdot 1$ | 4 |

Kết quả: `3 11 13 10 16 9 4`

## Độ phức tạp

- **Thời gian:** $O((n + m) \log(n + m))$
- **Bộ nhớ:** $O(n + m)$

## Mã nguồn (C++)

[Mã nguồn](../code/Signal%20Processing.cpp)
