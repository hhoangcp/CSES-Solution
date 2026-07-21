# Coding Company - Lời giải

**ID:** 1665 | **URL:** https://cses.fi/problemset/task/1665

## Đề bài

Cho $n$ lập trình viên với mức kỹ năng, chia thành các nhóm (bất kỳ phân hoạch nào) sao cho tổng penalty tối đa $x$. Penalty của nhóm là hiệu giữa kỹ năng cao nhất và thấp nhất. Đếm số cách chia hợp lệ modulo $10^9 + 7$.

## Hướng tiếp cận

### Sắp xếp + nhóm mở

Sắp xếp kỹ năng: $a_1 \leq a_2 \leq \cdots \leq a_n$. Sau khi sắp xếp, mọi nhóm trong phân hoạch tối ưu gồm các phần tử liên tiếp (nếu nhóm bỏ sót $a_k$ giữa $a_i$ và $a_j$, đưa $a_k$ vào không tăng penalty vì $a_k$ nằm giữa).

Xử lý theo thứ tự. **Nhóm mở** là nhóm đã có phần tử nhỏ nhất nhưng chưa có lớn nhất. Khi tiến từ $a_{i-1}$ sang $a_i$, khoảng mỗi nhóm mở rộng thêm $a_i - a_{i-1}$, nên tổng penalty tăng $j \cdot (a_i - a_{i-1})$ với $j$ là số nhóm mở.

### Trạng thái DP và chuyển tiếp

$dp[j][k]$ = số cách với $j$ nhóm mở và tổng penalty $k$ (offset 5000). Khi thêm lập trình viên $i$:

1. **Mở nhóm mới** ($j \to j+1$): $a_i$ bắt đầu nhóm mới. $dp[j+1][k + j \cdot d] \mathrel{+}= dp[j][k]$.
2. **Tham gia nhóm mở** ($j$ giữ): $a_i$ vào 1 trong $j$ nhóm, không đóng. $dp[j][k + j \cdot d] \mathrel{+}= j \cdot dp[j][k]$.
3. **Đóng nhóm** ($j \to j-1$): $a_i$ đóng 1 trong $j$ nhóm. $dp[j-1][k + j \cdot d] \mathrel{+}= j \cdot dp[j][k]$.
4. **Nhóm đơn** ($j$ giữ): $a_i$ tự thành nhóm (mở và đóng ngay). $dp[j][k + j \cdot d] \mathrel{+}= dp[j][k]$.

Với $d = a_i - a_{i-1}$. Trường hợp 2+4 gộp thành $(j + 1) \cdot dp[j][k]$.

Đáp án: $\sum_{t=0}^{x} dp[0][5000 + t]$ (0 nhóm mở = mọi nhóm đã đóng, penalty $\leq x$).

### Ví dụ

$n = 3, x = 2$, kỹ năng: $[2, 3, 5]$. Các cách chia hợp lệ:

- $\{2, 3\}, \{5\}$: penalty = $(3-2) + 0 = 1$
- $\{2\}, \{3, 5\}$: penalty = $0 + (5-3) = 2$
- $\{2\}, \{3\}, \{5\}$: penalty = $0$

Tổng: **3** cách.

## Độ phức tạp

- **Thời gian:** $O(n^2 \cdot x)$
- **Bộ nhớ:** $O(n \cdot x)$ (hoặc dùng mảng cuộn)

## Mã nguồn (C++)

[Mã nguồn](../code/Coding%20Company.cpp)
