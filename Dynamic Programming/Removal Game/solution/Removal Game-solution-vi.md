# Removal Game - Lời giải

**ID:** 1097 | **URL:** https://cses.fi/problemset/task/1097

## Hướng tiếp cận

### Phát biểu lại bài toán

Cho mảng $n$ số nguyên, hai người chơi thay phiên lấy một số từ đầu hoặc cuối mảng. Cả hai chơi tối ưu để tối đa điểm của mình. Tìm điểm tối đa của người chơi đầu tiên.

### Ý tưởng cốt lõi

Trò chơi có cấu trúc con tự nhiên là mảng con $[i, j]$. Gọi $dp[i][j]$ là điểm tối đa mà **người đang đi** đạt được từ mảng con $[i, j]$.

**Nhận xét quan trọng:** Tổng điểm hai người trên $[i, j]$ là hằng số $S(i,j) = \sum_{k=i}^{j} a_k$. Nếu người hiện tại lấy $a_i$, người kia đạt $dp[i+1][j]$ trên phần còn lại, nên người hiện tại đạt $S(i,j) - dp[i+1][j]$. Tương tự cho $a_j$. Vậy:

$$dp[i][j] = S(i,j) - \min\big(dp[i+1][j], dp[i][j-1]\big)$$

**Dạng triển khai (xen kẽ max/min):** Vì $S(i,j)$ là hằng số, ta viết lại theo lượt chơi dựa trên tính chẵn/lẻ của độ dài đoạn so với $n$:

- **Lượt người thứ nhất** (độ dài cùng tính chẵn/lẻ với $n$): $dp[i][j] = \max(dp[i+1][j] + a_i, dp[i][j-1] + a_j)$
- **Lượt người thứ hai** (độ dài khác tính chẵn/lẻ): $dp[i][j] = \min(dp[i+1][j], dp[i][j-1])$

Cách này tính trực tiếp điểm người thứ nhất mà không cần lưu $S(i,j)$.

**Tính đúng:** Quy nạp theo độ dài đoạn. Khi người thứ nhất chọn $a_i$, tổng điểm của họ là $a_i + (S(i{+}1,j) - dp[i{+}1][j]) = S(i,j) - dp[i{+}1][j]$; tính tối ưu của người kia trên $[i{+}1,j]$ được đảm bảo theo quy nạp. Lấy max trên cả hai lựa chọn cho kết quả tối ưu. Phép min xen kẽ trong code thể hiện việc người kia tối thiểu hóa lợi ích còn lại của người thứ nhất.

**Tối ưu không gian:** Vì $dp[i][j]$ chỉ phụ thuộc $dp[i+1][j]$ (hàng trước) và $dp[i][j-1]$ (cùng hàng), mảng cuộn 1D đủ dùng: `pre[j]` lưu hàng trước khi ghi đè.

### Thuật toán

1. Duyệt $i$ từ $n$ xuống $1$.
2. Với mỗi $i$, duyệt $j$ từ $i$ đến $n$.
3. Dùng tính chẵn/lẻ của $(j - i + 1)$ so với $n$ để chọn max hoặc min.
4. Xuất $dp[n]$.

### Ví dụ

Mảng $[4, 5, 1, 3]$, $n = 4$ (chẵn):

| $[i,j]$ | Độ dài | Lượt | $dp[i{+}1][j]$ | $dp[i][j{-}1]$ | $dp[i][j]$ |
|---------|--------|------|-----------------|-----------------|------------|
| $[4,4]$ | 1 | P2 | — | — | $0$ |
| $[3,3]$ | 1 | P2 | — | — | $0$ |
| $[3,4]$ | 2 | P1 | $0{+}3{=}3$ | $0{+}1{=}1$ | $3$ |
| $[2,2]$ | 1 | P2 | — | — | $0$ |
| $[2,3]$ | 2 | P1 | $0{+}1{=}1$ | $0{+}5{=}5$ | $5$ |
| $[2,4]$ | 3 | P2 | $5$ | $3$ | $3$ |
| $[1,1]$ | 1 | P2 | — | — | $0$ |
| $[1,2]$ | 2 | P1 | $0{+}5{=}5$ | $0{+}4{=}4$ | $5$ |
| $[1,3]$ | 3 | P2 | $5$ | $5$ | $5$ |
| $[1,4]$ | 4 | P1 | $5{+}3{=}8$ | $3{+}4{=}7$ | $\mathbf{8}$ |

Kết quả: người thứ nhất đạt $\mathbf{8}$ điểm. Cách chơi tối ưu: P1 lấy $a_4{=}3$, P2 lấy $a_1{=}4$, P1 lấy $a_2{=}5$, P2 lấy $a_3{=}1$.

## Độ phức tạp

- **Thời gian:** $O(n^2)$ — $O(n^2)$ trạng thái, mỗi trạng thái $O(1)$
- **Bộ nhớ:** $O(n)$ — mảng cuộn 1D

## Mã nguồn (C++)

[Mã nguồn](../code/Removal%20Game.cpp)
