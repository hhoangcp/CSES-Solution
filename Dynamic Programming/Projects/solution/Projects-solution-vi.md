# Projects - Lời giải

**ID:** 1140 | **URL:** https://cses.fi/problemset/task/1140

## Hướng tiếp cận

### Phát biểu lại bài toán

Có $n$ dự án, mỗi dự án có ngày bắt đầu $a_i$, ngày kết thúc $b_i$, và tiền thưởng $p_i$. Các dự án được chọn không được giao nhau về thời gian. Tìm tổng tiền thưởng tối đa.

### Ý tưởng cốt lõi

Đây là bài toán **lập lịch khoảng có trọng số** (Weighted Interval Scheduling). Sắp xếp các dự án theo ngày kết thúc $b_i$ tăng dần. Gọi $dp[i]$ là tổng tiền thưởng tối đa khi chỉ xét $i$ dự án đầu tiên (sau khi sắp xếp). Với mỗi dự án $i$:

- **Không chọn $i$:** $dp[i-1]$
- **Chọn $i$:** tìm $p$ lớn nhất sao cho $b_p < a_i$ (dự án cuối cùng kết thúc trước khi $i$ bắt đầu), rồi $dp[p] + p_i$

$$dp[i] = \max(dp[i-1], dp[p] + p_i)$$

Tìm $p$ bằng tìm kiếm nhị phân trên mảng $b$ đã sắp xếp. Trường hợp cơ sở: $dp[0] = 0$.

**Tại sao sắp xếp theo thời gian kết thúc:** Sau khi sắp xếp, nếu $b_i < a_j$, thì mọi dự án $k < i$ cũng thỏa $b_k \le b_i < a_j$, tức đều tương thích với $j$. Điều này cho phép dùng tìm kiếm nhị phân — ta chỉ cần tìm ranh giới.

**Tính đúng (cấu trúc con tối ưu):** Nếu dự án $i$ nằm trong nghiệm tối ưu, phần còn lại phải tối ưu cho $\{1, \ldots, p\}$ — nếu không, thay bằng nghiệm tối ưu thực sự cho $\{1, \ldots, p\}$ sẽ cho kết quả tốt hơn, mâu thuẫn. Quy nạp theo $i$, $dp[i]$ đúng bằng tổng tiền thưởng tối đa cho $i$ dự án đầu tiên.

### Thuật toán

1. Sắp xếp các dự án theo $b_i$ tăng dần.
2. Với $i = 1$ đến $n$:
   - Tìm kiếm nhị phân $p$ lớn nhất sao cho $b_p < a_i$.
   - $dp[i] = \max(dp[i-1], dp[p] + p_i)$.
3. Xuất $dp[n]$.

### Ví dụ

Đầu vào: 4 dự án — $(2,4,4)$, $(3,6,6)$, $(6,8,2)$, $(5,7,3)$.

Sau khi sắp xếp theo $b_i$: $(2,4,4)$, $(3,6,6)$, $(5,7,3)$, $(6,8,2)$.

| $i$ | $(a_i, b_i, p_i)$ | $p$ | $dp[i-1]$ | $dp[p]+p_i$ | $dp[i]$ |
|-----|---------------------|-----|-----------|-------------|---------|
| 1 | $(2, 4, 4)$ | 0 | 0 | 4 | 4 |
| 2 | $(3, 6, 6)$ | 0 | 4 | 6 | 6 |
| 3 | $(5, 7, 3)$ | 1 | 6 | $4+3=7$ | 7 |
| 4 | $(6, 8, 2)$ | 1 | 7 | $4+2=6$ | 7 |

Kết quả: $dp[4] = 7$. Chọn dự án $(2,4,4)$ và $(5,7,3)$.

## Độ phức tạp

- **Thời gian:** $O(n \log n)$ — sắp xếp + $n$ lần tìm kiếm nhị phân mỗi lần $O(\log n)$
- **Bộ nhớ:** $O(n)$ — cho mảng $dp$ và danh sách dự án

## Mã nguồn (C++)

[Mã nguồn](../code/Projects.cpp)
