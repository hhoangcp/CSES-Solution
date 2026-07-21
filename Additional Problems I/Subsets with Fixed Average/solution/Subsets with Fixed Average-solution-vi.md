# Subsets with Fixed Average - Lời giải

**ID:** 3302 | **URL:** https://cses.fi/problemset/task/3302

## Đề bài

Đếm số tập con không rỗng của mảng có trung bình bằng $a$. Kết quả modulo $10^9 + 7$.

## Hướng tiếp cận

### Biến đổi về bài toán tổng tập con

Trung bình tập con $S$ bằng $a$ khi và chỉ khi:

$$\frac{\sum_{x \in S} x}{|S|} = a \iff \sum_{x \in S} (x - a) = 0$$

Đặt $b_i = x_i - a$. Bài toán quy về: đếm số tập con không rỗng của $b$ có tổng bằng 0. Ánh xạ $S \mapsto \{x - a : x \in S\}$ là song ánh, nên số lượng được bảo toàn.

### Knapsack DP

Dùng $dp[s]$ = số tập con có tổng $s$ (dịch chuyển bằng OFFSET để xử lý tổng âm). $\text{OFFSET} = n \times 500 = 250000$, mọi tổng khả dĩ $s \in [-\text{OFFSET}, \text{OFFSET}]$ ánh xạ sang chỉ số mảng hợp lệ.

Với mỗi $b_i$:
- Nếu $b_i \geq 0$: duyệt $s$ từ cao xuống thấp (Knapsack 0/1 — tránh đếm trùng phần tử).
- Nếu $b_i < 0$: duyệt $s$ từ thấp lên cao.

$$dp[s + b_i] \mathrel{+}= dp[s]$$

Kết quả: $dp[\text{OFFSET}] - 1$ (trừ tập rỗng).

### Ví dụ minh họa

$n = 5, a = 2$, $x = [1, 1, 2, 3, 4]$, $b = [-1, -1, 0, 1, 2]$.

Các tập con của $b$ có tổng bằng 0:

| # | Phần tử từ $b$ | Tổng | Giá trị $x$ tương ứng |
|---|-----------------|------|----------------------|
| 1 | $\{0\}$ | 0 | $\{2\}$ |
| 2 | $\{-1, 1\}$ | 0 | $\{1, 3\}$ |
| 3 | $\{-1, 1\}$ | 0 | $\{1, 3\}$ (số 1 khác) |
| 4 | $\{-1, 0, 1\}$ | 0 | $\{1, 2, 3\}$ |
| 5 | $\{-1, 0, 1\}$ | 0 | $\{1, 2, 3\}$ (số 1 khác) |
| 6 | $\{-1, -1, 2\}$ | 0 | $\{1, 1, 4\}$ |
| 7 | $\{-1, -1, 0, 2\}$ | 0 | $\{1, 1, 2, 4\}$ |

Đáp án: **7**.

## Độ phức tạp

- **Thời gian:** $O(n \cdot n \cdot \max(x_i))$ — khoảng $500 \times 500000 \approx 2.5 \times 10^8$ phép cộng đơn giản, chạy trong 1 giây
- **Bộ nhớ:** $O(n \cdot \max(x_i))$ — mảng $dp$ kích thước $500000$

## Mã nguồn (C++)

[Mã nguồn](../code/Subsets%20with%20Fixed%20Average.cpp)
