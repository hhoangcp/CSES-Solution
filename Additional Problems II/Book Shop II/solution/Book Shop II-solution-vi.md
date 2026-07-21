# Book Shop II - Lời giải

**ID:** 1159 | **URL:** https://cses.fi/problemset/task/1159

## Đề bài

Có $n$ cuốn sách, mỗi cuốn giá $h_i$, $s_i$ trang, tối đa $k_i$ bản. Ngân sách $x$. Tìm tổng số trang lớn nhất khi mua tối đa $k_i$ bản mỗi sách.

## Hướng tiếp cận

### Bounded Knapsack với tối ưu Deque

Công thức chuyển cho sách $i$ tại dung lượng $j$:

$$dp[i][j] = \max_{0 \leq t \leq k_i} \left( dp[i-1][j - t \cdot h_i] + t \cdot s_i \right)$$

Duyệt trâu mất $O(n \cdot x \cdot k_i)$. Tối ưu bằng **lớp dư + Deque**:

Với mỗi sách $i$, nhóm dung lượng theo lớp dư $r \in [0, h_i - 1]$. Các dung lượng $r, r + h_i, r + 2h_i, \ldots$ tạo dãy cấp số cộng. Trong mỗi nhóm, chuyển tiếp là sliding window max trên tối đa $k_i + 1$ phần tử liên tiếp — Deque duy trì ứng viên theo thứ tự giảm giá trị hiệu chỉnh $dp[i-1][j'] - j'/h_i \cdot s_i$, loại phần tử ngoài cửa sổ ở đầu và phần tử bị trội ở đuôi.

Mỗi sách xử lý trong $O(x)$, tổng cộng $O(n \cdot x)$.

### Thuật toán

1. Khởi tạo $dp[0][j] = 0$.
2. Với mỗi sách $i$:
   - Nếu $h_i = 0$: cộng $k_i \cdot s_i$ trang cho mọi trạng thái.
   - Ngược lại, với mỗi lớp dư $r \in [0, h_i - 1]$:
     - Xử lý dung lượng $j = r, r + h_i, r + 2h_i, \ldots$ theo thứ tự.
     - Deque duy trì ứng viên tốt nhất; loại đầu nếu ngoài cửa sổ ($j - \text{front} > k_i \cdot h_i$), loại đuôi nếu bị trội.
     - $dp[i][j] = dp[i-1][\text{front}] + (j - \text{front}) / h_i \cdot s_i$.
3. Đáp án: $\max_j dp[n][j]$.

### Ví dụ

$n = 3$, $x = 10$, giá $[2,6,3]$, trang $[8,5,4]$, bản $[3,5,2]$.

Tối ưu: 3 bản sách 1 (chi phí 6, 24 trang) + 1 bản sách 3 (chi phí 3, 4 trang) = chi phí 9, **28 trang**.

## Độ phức tạp

- **Thời gian:** $O(n \cdot x)$
- **Bộ nhớ:** $O(n \cdot x)$ (hoặc $O(x)$ với mảng cuộn)

## Mã nguồn (C++)

[Mã nguồn](../code/Book%20Shop%20II.cpp)
