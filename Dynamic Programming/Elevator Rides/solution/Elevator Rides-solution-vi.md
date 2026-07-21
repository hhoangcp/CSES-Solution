# Elevator Rides - Lời giải

**ID:** 1653 | **URL:** https://cses.fi/problemset/task/1653

## Hướng tiếp cận

### Tóm tắt bài toán

Có $n$ người có cân nặng $w_i$ và thang máy tải trọng tối đa $x$. Tìm số chuyến ít nhất để chở tất cả. Mỗi người đi đúng một chuyến.

### Ý tưởng chính

Vì $n \le 20$, dùng **quy hoạch động bitmask**. Biểu diễn tập con người bằng bitmask $S$. Với mỗi tập con, lưu cặp $(r, w)$ so sánh theo thứ tự từ điển: $r$ = số chuyến tối thiểu, $w$ = trọng lượng tối thiểu trong chuyến cuối (với cùng $r$).

Việc lưu $w$ là cần thiết: không có $w$, ta không biết chuyến cuối còn chỗ cho người tiếp theo hay không. Với $w$, sức chứa còn lại là $x - w$.

Với mỗi người $j \in S$, gọi $(R, W) = dp[S \setminus \{j\}]$:

- **Chuyến cuối còn chỗ** ($W + w_j \le x$): thêm người $j$ vào chuyến cuối. Trạng thái mới: $(R, W + w_j)$.
- **Chuyến cuối đã đầy** ($W + w_j > x$): bắt đầu chuyến mới. Trạng thái mới: $(R + 1, \min(W, w_j))$.

$$dp[S] = \min_{j \in S} \begin{cases} (R, W + w_j) & \text{nếu } W + w_j \le x \\ (R + 1, \min(W, w_j)) & \text{nếu } W + w_j > x \end{cases}$$

**Tại sao dùng $\min(W, w_j)$:** Khi bắt đầu chuyến mới, ta có thể đổi thứ tự các chuyến — "chuyến cuối" trong biểu diễn không nhất thiết phải là chuyến chứa người $j$. Ta giữ chuyến nhẹ hơn làm chuyến cuối để tối đa sức chứa còn lại. Vì các chuyến thực chất không có thứ tự, cả hai cách xếp đều hợp lệ, và giữ trọng lượng nhỏ hơn luôn tốt hơn hoặc bằng.

Trường hợp cơ sở: $dp[0] = (1, 0)$ — một chuyến rỗng, sẵn sàng đón người. Kết quả: $dp[2^n - 1].r$.

### Thuật toán

1. Khởi tạo $dp[0] = (1, 0)$.
2. Với $S = 1$ đến $2^n - 1$:
   - Đặt $dp[S] = (\infty, 0)$.
   - Với mỗi $j$ mà bit $j$ của $S$ bằng 1:
     - $(R, W) = dp[S \setminus \{j\}]$.
     - Nếu $W + w_j \le x$: ứng cử viên $= (R, W + w_j)$.
     - Ngược lại: ứng cử viên $= (R + 1, \min(W, w_j))$.
     - $dp[S] = \min(dp[S], \text{ứng cử viên})$ (theo thứ tự từ điển).
3. In ra $dp[2^n - 1].r$.

### Ví dụ minh họa

Input: $n = 4$, $x = 10$, $w = [4, 8, 6, 1]$.

| $S$ | Tập | $dp[S]$ | Chuyển chính |
|:---:|:---|:---:|:---|
| 0000 | $\emptyset$ | (1, 0) | Cơ sở |
| 0001 | $\{0\}$ | (1, 4) | $0{+}4 \le 10$ |
| 0010 | $\{1\}$ | (1, 8) | $0{+}8 \le 10$ |
| 0011 | $\{0,1\}$ | (2, 4) | Cả hai $4{+}8{>}10 \to$ chuyến mới, $\min(4,8){=}4$ |
| 0100 | $\{2\}$ | (1, 6) | $0{+}6 \le 10$ |
| 0101 | $\{0,2\}$ | (1, 10) | $6{+}4 \le 10$ |
| 0111 | $\{0,1,2\}$ | (2, 8) | Từ $\{0,2\}$: $10{+}8{>}10 \to (2, \min(10,8))$ |
| 1111 | $\{0,1,2,3\}$ | (2, 9) | Từ $\{0,2,3\}$: $1{+}8 \le 10 \to (2, 9)$ |

Kết quả: 2 chuyến — ví dụ $\{4, 6\}$ và $\{8, 1\}$.

## Độ phức tạp

- **Thời gian:** $O(2^n \cdot n)$
- **Không gian:** $O(2^n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Elevator%20Rides.cpp)
