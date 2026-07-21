# Counting Coprime Pairs - Lời giải

**ID:** 2417 | **URL:** https://cses.fi/problemset/task/2417

## Phương pháp

### Tóm tắt bài toán

Cho $n$ số nguyên dương $x_1, x_2, \ldots, x_n$ ($n \leq 10^5$, $x_i \leq 10^6$). Đếm số cặp $(i, j)$ với $i < j$ sao cho $\gcd(x_i, x_j) = 1$.

### Ý tưởng chính

Thay vì đếm trực tiếp cặp nguyên tố cùng nhau, đếm cặp theo tính chia hết cho GCD rồi dùng kỹ thuật sàng trừ bội để trích xuất cặp có GCD đúng bằng 1.

**Định nghĩa.** Gọi $f(d)$ = số cặp có $\gcd$ đúng bằng $d$, và $g(d)$ = số cặp mà cả hai phần tử đều chia hết cho $d$ (tức $d \mid \gcd$). Khi đó:

$$g(d) = \sum_{k=1}^{\lfloor M/d \rfloor} f(k \cdot d) = f(d) + f(2d) + f(3d) + \cdots$$

**Tính $g(d)$.** Gọi $N(d)$ = số phần tử chia hết cho $d$, tính bằng cách cộng dồn mảng tần số tại các bội của $d$. Khi đó $g(d) = \binom{N(d)}{2}$.

**Phục hồi $f(d)$.** Biến đổi hệ thức: $f(d) = g(d) - f(2d) - f(3d) - \cdots$. Duyệt $d$ từ $M$ xuống $1$; khi tính $f(d)$, tất cả $f(kd)$ với $k \geq 2$ đã được biết. Kỹ thuật này tương đương nghịch đảo Möbius nhưng không cần tính hàm Möbius tường minh.

*Tính đúng đắn (quy nạp ngược).* Cơ sở: $f(M) = g(M)$ vì không có bội vượt $M$. Bước quy nạp: giả sử $f(k) = dp[k]$ với mọi $k > d$, thì $dp[d] = g(d) - \sum_{k \geq 2} f(kd) = g(d) - (g(d) - f(d)) = f(d)$.

Đáp án bài toán là $f(1)$.

### Thuật toán

1. Xây mảng tần số $\text{cnt}[v]$ từ mảng đầu vào.
2. Với mỗi $d$ từ $1$ đến $M$: tính $N(d)$ bằng cách cộng $\text{cnt}[k \cdot d]$, rồi $g(d) = \binom{N(d)}{2}$.
3. Duyệt $d$ từ $M$ xuống $1$: đặt $dp[d] = g(d) - \sum_{k=2}^{\lfloor M/d \rfloor} dp[k \cdot d]$.
4. Xuất $dp[1]$.

### Ví dụ minh họa

Mảng $[2, 3, 4, 6]$ ($M = 6$):

| $d$ | Bội trong mảng | $N(d)$ | $g(d)$ | Khấu trừ | $f(d)$ |
|:---:|:---:|:---:|:---:|:---|:---:|
| 6 | $\{6\}$ | 1 | 0 | — | 0 |
| 4 | $\{4\}$ | 1 | 0 | — | 0 |
| 3 | $\{3,6\}$ | 2 | 1 | $1 - f(6) = 1$ | 1 |
| 2 | $\{2,4,6\}$ | 3 | 3 | $3 - f(4) - f(6) = 3$ | 3 |
| 1 | $\{2,3,4,6\}$ | 4 | 6 | $6 - f(2) - f(3) - f(4) - f(5) - f(6) = 2$ | 2 |

$f(1) = 2$. Cặp nguyên tố cùng nhau: $(2, 3)$ và $(3, 4)$.

## Độ phức tạp

- **Thời gian:** $O(n + M \log M)$ — mảng tần số $O(n)$, sàng $O(M \log M)$ theo chuỗi điều hòa
- **Bộ nhớ:** $O(M)$
