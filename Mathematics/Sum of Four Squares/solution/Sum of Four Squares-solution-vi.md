# Sum of Four Squares - Lời giải

**ID:** 3355 | **URL:** https://cses.fi/problemset/task/3355

## Phương pháp

### Tóm tắt bài toán

Cho số nguyên không âm $n$ ($0 \le n \le 10^7$), tìm bốn số nguyên không âm $a, b, c, d$ sao cho $n = a^2 + b^2 + c^2 + d^2$. Có tối đa $t = 1000$ test case, tổng tất cả $n$ không vượt $10^7$.

### Ý tưởng chính

**Định lý bốn bình phương Lagrange (1770):** Mọi số nguyên không âm đều biểu diễn được dưới dạng tổng bốn bình phương. Điều này đảm bảo lời giải luôn tồn tại.

Phân rã $n = s_1 + s_2$ sao cho cả $s_1$ và $s_2$ đều là tổng hai bình phương. Nếu $s_1 = a^2 + b^2$ và $s_2 = c^2 + d^2$, thì $n = a^2 + b^2 + c^2 + d^2$.

**Tại sao luôn tìm được điểm chia:** Theo định lý Lagrange, $n = a^2 + b^2 + c^2 + d^2$. Đặt $s_1 = a^2 + b^2$ và $s_2 = c^2 + d^2$, ta có $n = s_1 + s_2$ với cả hai đều là tổng hai bình phương. Việc duyệt tuyến tính từ $0$ đến $n$ chắc chắn sẽ bắt gặp điểm chia này.

**Tiền xử lý:** Với mọi $s \le 10^7$, tính $avail[s]$ (s có phải tổng hai bình phương không) và $sum[s]$ (cặp $(a, b)$ với $s = a^2 + b^2$). Duyệt $i, j \ge 0$ với $i^2 + j^2 \le 10^7$, đánh dấu $avail[i^2+j^2] = \text{true}$ và lưu $sum[i^2+j^2] = (i, j)$.

### Thuật toán

1. **Tiền xử lý:** Với mọi $i, j \ge 0$ với $i^2 + j^2 \le 10^7$: đặt $avail[i^2+j^2] = \text{true}$, $sum[i^2+j^2] = (i, j)$.
2. **Truy vấn:** Với mỗi $n$, duyệt $i$ từ $0$ đến $n$. Nếu $avail[i]$ và $avail[n-i]$ đều true, xuất $sum[i]$ và $sum[n-i]$.

### Ví dụ minh họa

$n = 30$: duyệt tìm thấy $i = 1$ với $avail[1] = \text{true}$ ($1 = 1^2 + 0^2$) và $avail[29] = \text{true}$ ($29 = 5^2 + 2^2$). Kết quả: $1, 0, 5, 2$ ($1 + 0 + 25 + 4 = 30$) $\checkmark$.

$n = 5$: duyệt tìm thấy $i = 0$ với $avail[0] = \text{true}$ và $avail[5] = \text{true}$ ($5 = 2^2 + 1^2$). Kết quả: $0, 0, 2, 1$ $\checkmark$.

## Độ phức tạp

- **Thời gian:** $O(N)$ tiền xử lý ($N = 10^7$), $O(n)$ mỗi truy vấn (thực tế tìm rất nhanh)
- **Không gian:** $O(N)$

## Mã nguồn (C++)

[Mã nguồn](../code/Sum%20of%20Four%20Squares.cpp)
