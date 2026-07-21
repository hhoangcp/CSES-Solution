# Minimizing Coins - Lời giải

**ID:** 1634 | **URL:** https://cses.fi/problemset/task/1634

## Hướng tiếp cận

### Phát biểu lại bài toán

Cho $n$ loại đồng xu có giá trị $c_1, \ldots, c_n$ và tổng mục tiêu $x$, tìm số đồng xu ít nhất để tạo ra tổng $x$ (mỗi loại dùng được vô hạn). Nếu không thể, xuất $-1$.

### Ý tưởng cốt lõi

Gọi $dp[i]$ là số đồng xu tối thiểu để tạo tổng $i$ (hoặc $+\infty$ nếu không thể). Xét **đồng xu cuối cùng** được thêm trong phương án tối ưu cho tổng $i$: nếu nó có giá trị $c_j$, thì phần còn lại $i - c_j$ cũng phải được giải tối ưu. Lấy minimum trên mọi lựa chọn đồng xu cuối:

$$dp[i] = \min_{\substack{j=1,\ldots,n \\ i \ge c_j}} \big(dp[i - c_j] + 1\big)$$

Trường hợp cơ sở: $dp[0] = 0$. Khởi tạo $dp[i] = +\infty$ cho $i \ge 1$.

**Tính đúng (cấu trúc con tối ưu):** Nếu phần còn lại $i - c_j$ có thể tạo bằng ít hơn $dp[i - c_j]$ đồng xu, thì thay thế sẽ cho phương án tốt hơn cho $i$ — mâu thuẫn với tính tối ưu. Công thức cũng bao quát mọi trường hợp vì mọi cấu hình tối ưu đều kết thúc bằng một đồng xu nào đó $c_j$.

### Thuật toán

1. Đặt $dp[0] = 0$, $dp[i] = +\infty$ cho $i = 1, \ldots, x$.
2. Với $i = 1$ đến $x$: tính $dp[i]$ theo công thức truy hồi.
3. Xuất $dp[x]$ nếu hữu hạn, ngược lại xuất $-1$.

### Ví dụ

Đồng xu $\{1, 5, 7\}$, $x = 11$:

| $i$ | $dp[i]$ | Đồng xu cuối tốt nhất |
|-----|---------|------------------------|
| 0 | 0 | — |
| 1 | $dp[0]+1 = 1$ | 1 |
| 5 | $dp[0]+1 = 1$ | 5 |
| 6 | $dp[5]+1 = 2$ | 5 |
| 7 | $dp[0]+1 = 1$ | 7 |
| 10 | $dp[5]+1 = 2$ | 5 |
| 11 | $\min(dp[10]+1, dp[6]+1, dp[4]+1) = 3$ | 5 |

Kết quả: $dp[11] = 3$ (ví dụ: $5 + 5 + 1$).

## Độ phức tạp

- **Thời gian:** $O(n \cdot x)$ — với mỗi tổng $1 \ldots x$, duyệt $n$ loại đồng xu
- **Bộ nhớ:** $O(x)$ — cho mảng $dp$

## Mã nguồn (C++)

[Mã nguồn](../code/Minimizing%20Coins.cpp)
