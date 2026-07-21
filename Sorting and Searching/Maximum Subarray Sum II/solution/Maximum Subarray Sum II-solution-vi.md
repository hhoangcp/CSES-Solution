# Maximum Subarray Sum II - Lời giải

**ID:** 1644 | **URL:** https://cses.fi/problemset/task/1644

## Phương pháp

### Tóm tắt bài toán

Cho mảng $n$ số nguyên, tìm tổng lớn nhất của mảng con liên tiếp có độ dài trong đoạn $[a, b]$.

### Ý tưởng chính

Dùng tổng tiền tố: $\text{pref}[0] = 0$, $\text{pref}[i] = \sum_{j=1}^{i} x_j$. Tổng mảng con $[l, r]$ bằng $\text{pref}[r] - \text{pref}[l-1]$. Đặt $R = r$, $L = l - 1$, ràng buộc độ dài trở thành $R - b \le L \le R - a$. Với mỗi $R$ cố định, $\text{pref}[R]$ là hằng số nên ta cần $\min_{L \in [R-b, R-a]} \text{pref}[L]$ — đây là bài toán range minimum query trên cửa sổ trượt. Dùng segment tree để truy vấn minimum trên đoạn trong $O(\log n)$, hoặc deque (sliding window minimum) để đạt $O(n)$.

### Thuật toán (Segment Tree)

1. Xây segment tree trên mảng $\text{pref}[0..n]$, khởi tạo $\text{pref}[0] = 0$.
2. Duyệt $R$ từ $1$ đến $n$:
   - Cập nhật $\text{pref}[R]$ và nạp vào segment tree.
   - Nếu $R \ge a$: truy vấn $\min$ trên đoạn $[\max(0, R-b), R-a]$, cập nhật $\text{res} = \max(\text{res}, \text{pref}[R] - \text{min\_val})$.
3. Xuất $\text{res}$.

### Ví dụ minh họa

Mảng $[-1, 3, -2, 5, 3, -5, 2, 2]$, $a = 1$, $b = 2$, $n = 8$.

$\text{pref} = [0, -1, 2, 0, 5, 8, 3, 5, 7]$.

| $R$ | $\text{pref}[R]$ | Miền $L$ | $\min \text{pref}[L]$ | $\text{pref}[R] - \min$ | $\text{res}$ |
|-----|-------------------|----------|------------------------|--------------------------|--------------|
| 1 | $-1$ | $[0, 0]$ | 0 | $-1$ | $-1$ |
| 2 | $2$ | $[0, 1]$ | $-1$ | $3$ | $3$ |
| 3 | $0$ | $[1, 2]$ | $-1$ | $1$ | $3$ |
| 4 | $5$ | $[2, 3]$ | $0$ | $5$ | $5$ |
| 5 | $8$ | $[3, 4]$ | $0$ | **8** | **8** |
| 6 | $3$ | $[4, 5]$ | $5$ | $-2$ | $8$ |
| 7 | $5$ | $[5, 6]$ | $3$ | $2$ | $8$ |
| 8 | $7$ | $[6, 7]$ | $3$ | $4$ | $8$ |

Kết quả: **8** (mảng con $[5, 3]$ tại vị trí 4–5).

## Độ phức tạp

- **Thời gian:** $O(n \log n)$ — segment tree; có thể tối ưu thành $O(n)$ bằng deque
- **Không gian:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Maximum%20Subarray%20Sum%20II.cpp)
