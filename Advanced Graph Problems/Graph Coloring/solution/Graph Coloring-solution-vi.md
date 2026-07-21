# Graph Coloring - Lời giải

**ID:** 3308 | **URL:** https://cses.fi/problemset/task/3308

## Phương pháp

### Tóm tắt bài toán

Cho đồ thị đơn $n \leq 16$ đỉnh, $m$ cạnh. Tô màu các đỉnh bằng số màu tối thiểu sao cho không có cạnh nào nối hai đỉnh cùng màu (số sắc).

### Ý tưởng chính

Tập con các đỉnh có thể tô cùng một màu iff nó là **tập độc lập**. Số sắc bằng số tập độc lập tối thiểu để phân hoạch toàn bộ tập đỉnh. Công thức QHĐ: $dp[mask] = \min(dp[mask \oplus submask] + 1)$ trên mọi tập con độc lập `submask` của `mask`. Mỗi bước `+1` tương ứng dùng một màu cho tập độc lập `submask`, phần còn lại đã tối ưu trước đó. Vì xét tất cả tập con hợp lệ, `dp[full_mask]` chắc chắn là số sắc tối ưu.

### Thuật toán

1. **Tiền xử lý:** Với mỗi mask từ $0$ đến $2^n-1$, kiểm tra có phải tập độc lập không. Lưu `valid[mask]`.
2. **QHĐ:** `dp[0] = 0`, $dp[mask] = \min(dp[mask \oplus submask] + 1)$ với mọi `submask ⊆ mask` và `valid[submask]`.
3. **Truy vết:** Dùng `trace[mask]` lưu `submask` tối ưu, gán màu cho từng đỉnh.

### Ví dụ minh họa

$n=4$, cạnh: 1-2, 2-3, 3-4, 4-1 (chu trình $C_4$). Tập độc lập tối đa: $\{1,3\}$ và $\{2,4\}$.

`dp[1111] = dp[\{1,3\}] + 1 = dp[\{2,4\}] + 1 = 2`. Số sắc = 2.

## Độ phức tạp

- **Thời gian:** $O(3^n + m \cdot 2^n)$
- **Không gian:** $O(2^n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Graph%20Coloring.cpp)
