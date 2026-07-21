# Maximum Manhattan Distances - Lời giải

**ID:** 3410 | **URL:** https://cses.fi/problemset/task/3410

## Phương pháp

### Tóm tắt bài toán

Tập hợp ban đầu rỗng, $n$ điểm được thêm vào tuần tự. Sau mỗi lần thêm, tính khoảng cách Manhattan lớn nhất giữa hai điểm bất kỳ.

### Ý tưởng chính

Khoảng cách Manhattan giữa $(x_1, y_1)$ và $(x_2, y_2)$ có thể viết lại bằng cách loại bỏ giá trị tuyệt đối:

$$|x_1 - x_2| + |y_1 - y_2| = \max\left(|u_1 - u_2|,\ |v_1 - v_2|\right)$$

với $u = x + y$ và $v = x - y$. Đồng nhất thức này đúng vì xét 4 trường hợp dấu của $(x_1 - x_2)$ và $(y_1 - y_2)$: khi cùng dấu, $|x_1 - x_2| + |y_1 - y_2| = |u_1 - u_2|$; khi khác dấu, $|x_1 - x_2| + |y_1 - y_2| = |v_1 - v_2|$. Lấy max của hai trường hợp bao trùm tất cả.

Phép biến đổi này đưa khoảng cách Manhattan 2D về max của hai hiệu tuyệt đối 1D. Khoảng cách lớn nhất trên tất cả các cặp khi đó là:

$$\max\left(\max(u) - \min(u),\ \max(v) - \min(v)\right)$$

vì $|u_i - u_j|$ đạt max tại cặp có giá trị $u$ cực trị (tương tự với $v$). Duy trì bốn giá trị — $\max(u)$, $\min(u)$, $\max(v)$, $\min(v)$ — cập nhật mỗi giá trị trong $O(1)$ khi có điểm mới. Kết quả sau mỗi lần thêm là $\max(\max_u - \min_u,\ \max_v - \min_v)$.

### Thuật toán

1. Khởi tạo $\max_u = -\infty$, $\min_u = +\infty$, $\max_v = -\infty$, $\min_v = +\infty$.
2. Với mỗi điểm $(x, y)$:
   - Tính $u = x + y$ và $v = x - y$.
   - Cập nhật $\max_u = \max(\max_u, u)$, $\min_u = \min(\min_u, u)$, tương tự cho $v$.
   - Xuất $\max(\max_u - \min_u,\ \max_v - \min_v)$.

### Ví dụ minh họa

5 điểm: $(1,1), (3,2), (2,4), (2,1), (4,5)$.

| Điểm | $u$ | $v$ | $[\min_u, \max_u]$ | $[\min_v, \max_v]$ | Kết quả |
|------|-----|-----|---------------------|---------------------|---------|
| $(1,1)$ | 2 | 0 | $[2, 2]$ | $[0, 0]$ | 0 |
| $(3,2)$ | 5 | 1 | $[2, 5]$ | $[0, 1]$ | $\max(3, 1) = 3$ |
| $(2,4)$ | 6 | $-2$ | $[2, 6]$ | $[-2, 1]$ | $\max(4, 3) = 4$ |
| $(2,1)$ | 3 | 1 | $[2, 6]$ | $[-2, 1]$ | $\max(4, 3) = 4$ |
| $(4,5)$ | 9 | $-1$ | $[2, 9]$ | $[-2, 1]$ | $\max(7, 3) = 7$ |

## Độ phức tạp

- **Thời gian:** $O(n)$
- **Không gian:** $O(1)$

## Mã nguồn (C++)

[Mã nguồn](../code/Maximum%20Manhattan%20Distances.cpp)
