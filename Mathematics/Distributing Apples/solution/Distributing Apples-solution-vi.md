# Distributing Apples - Lời giải

**ID:** 1716 | **URL:** https://cses.fi/problemset/task/1716

## Phương pháp

### Tóm tắt bài toán

Có $n$ đứa trẻ và $m$ quả táo giống nhau ($1 \le n, m \le 10^6$). Mỗi quả táo phải phân phối cho một đứa trẻ; một đứa trẻ có thể nhận 0 quả. Đếm số cách phân phối, kết quả lấy modulo $10^9+7$.

### Ý tưởng chính

Đây là bài toán **Stars and Bars** cổ điển: phân phối $m$ vật giống nhau cho $n$ nhóm, cho phép nhóm rỗng.

Biểu diễn mỗi cách phân phối bằng một dãy gồm $m$ sao ($\star$) và $n-1$ thanh ($|$). Số sao trước thanh 1 thuộc đứa 1, số sao giữa thanh 1 và thanh 2 thuộc đứa 2, v.v. Tồn tại song ánh giữa các cách phân phối và các dãy $n+m-1$ ký tự có $n-1$ thanh, nên đáp án là:

$$\binom{n + m - 1}{n - 1} = \binom{n + m - 1}{m}$$

*Chứng minh thay thế.* Mỗi cách phân phối là một nghiệm nguyên không âm của $x_1 + x_2 + \cdots + x_n = m$. Đặt $y_i = x_i + 1$, bài toán biến thành $y_1 + y_2 + \cdots + y_n = m + n$ với $y_i \ge 1$, có $\binom{m+n-1}{n-1}$ nghiệm nguyên dương.

**Tính modulo.** Với $p = 10^9+7$ nguyên tố:

$$\binom{n+m-1}{m} \equiv (n+m-1)! \cdot ((n-1)!)^{-1} \cdot (m!)^{-1} \pmod{p}$$

Tính trước giai thừa và nghịch đảo giai thừa tới $n + m - 1$.

### Thuật toán

1. Tính trước $fact[i] = i! \bmod p$ và $inv\_f[i] = (i!)^{-1} \bmod p$ tới $n + m - 1$.
2. Xuất $fact[n+m-1] \cdot inv\_f[n-1] \cdot inv\_f[m] \bmod p$.

### Ví dụ minh họa

$n = 3$, $m = 2$: $\binom{4}{2} = 6$.

| Cách phân phối | $x_1$ | $x_2$ | $x_3$ |
|:---:|:---:|:---:|:---:|
| $\star\star\mid\mid$ | 2 | 0 | 0 |
| $\star\mid\star\mid$ | 1 | 1 | 0 |
| $\star\mid\mid\star$ | 1 | 0 | 1 |
| $\mid\star\star\mid$ | 0 | 2 | 0 |
| $\mid\star\mid\star$ | 0 | 1 | 1 |
| $\mid\mid\star\star$ | 0 | 0 | 2 |

## Độ phức tạp

- **Thời gian:** $O(n + m)$ — tiền xử lý giai thừa
- **Bộ nhớ:** $O(n + m)$
