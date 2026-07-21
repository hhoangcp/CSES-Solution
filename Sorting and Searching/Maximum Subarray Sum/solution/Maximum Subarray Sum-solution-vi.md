# Maximum Subarray Sum - Lời giải

**ID:** 1643 | **URL:** https://cses.fi/problemset/task/1643

## Phương pháp

### Tóm tắt bài toán

Cho mảng $n$ số nguyên (có thể âm), tìm tổng lớn nhất của một mảng con không rỗng (liên tiếp).

### Ý tưởng chính

Định nghĩa tổng tiền tố $P_0 = 0$, $P_i = x_1 + \cdots + x_i$. Tổng mảng con $[a, b]$ bằng $P_b - P_{a-1}$. Để tối đa hóa $P_b - P_{a-1}$ tại mỗi $b$, ta cần $P_{a-1}$ nhỏ nhất có thể trong các vị trí trước $b$. Duy trì $h = \min_{0 \le j < i} P_j$ và $S = P_i$, tại mỗi bước cập nhật $\text{res} = \max(\text{res}, S - h)$. Công thức đúng vì: với mảng con tối ưu $[a, b]$, tại bước $i = b$ ta có $h \le P_{a-1}$ nên $S - h \ge P_b - P_{a-1} = \text{đáp án}$, tức $\text{res} \ge \text{đáp án}$; ngược lại $\text{res}$ luôn là tổng của một mảng con hợp lệ nên $\text{res} \le \text{đáp án}$. Vậy $\text{res} = \text{đáp án}$. Khởi tạo $h = 0$ (tổng tiền tố rỗng $P_0$) để xét mảng con bắt đầu từ $x_1$; $\text{res} = -\infty$ vì đáp án có thể âm.

### Thuật toán

1. Khởi tạo $S = 0$, $h = 0$, $\text{res} = -\infty$.
2. Với $i$ từ $1$ đến $n$:
   - $S \mathrel{+}= x_i$.
   - $\text{res} = \max(\text{res}, S - h)$.
   - $h = \min(h, S)$.
3. Xuất $\text{res}$.

### Ví dụ minh họa

Mảng $[-1, 3, -2, 5, 3, -5, 2, 2]$, $n = 8$.

| $i$ | $x_i$ | $S$ | $h$ (trước) | $S - h$ | $\text{res}$ | $h$ (sau) |
|-----|-------|-----|-------------|---------|--------------|-----------|
| 1 | $-1$ | $-1$ | 0 | $-1$ | $-1$ | $-1$ |
| 2 | $3$ | $2$ | $-1$ | $3$ | $3$ | $-1$ |
| 3 | $-2$ | $0$ | $-1$ | $1$ | $3$ | $-1$ |
| 4 | $5$ | $5$ | $-1$ | $6$ | $6$ | $-1$ |
| 5 | $3$ | $8$ | $-1$ | $9$ | **9** | $-1$ |
| 6 | $-5$ | $3$ | $-1$ | $4$ | $9$ | $-1$ |
| 7 | $2$ | $5$ | $-1$ | $6$ | $9$ | $-1$ |
| 8 | $2$ | $7$ | $-1$ | $8$ | $9$ | $-1$ |

Mảng con tối ưu: $[3, -2, 5, 3]$ (vị trí 2–5), tổng = **9**.

## Độ phức tạp

- **Thời gian:** $O(n)$
- **Không gian:** $O(1)$

## Mã nguồn (C++)

[Mã nguồn](../code/Maximum%20Subarray%20Sum.cpp)
