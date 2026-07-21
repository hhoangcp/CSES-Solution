# Inversion Probability - Lời giải

**ID:** 1728 | **URL:** https://cses.fi/problemset/task/1728

## Phương pháp

### Tóm tắt bài toán

Cho $n$ số nguyên $x_1, x_2, \ldots, x_n$, mỗi $x_i$ được chọn ngẫu nhiên đều trong đoạn $[1, r_i]$. Một nghịch đảo là cặp $(a, b)$ với $a < b$ và $x_a > x_b$. Tính kỳ vọng số nghịch đảo, làm tròn 6 chữ số thập phân (làm tròn ngân hàng).

### Ý tưởng chính

Theo **tính tuyến tính của kỳ vọng**, kỳ vọng số nghịch đảo bằng tổng xác suất nghịch đảo trên tất cả các cặp, bất kể các biến có độc lập hay không:

$$E[\text{số nghịch đảo}] = \sum_{1 \le i < j \le n} P(x_i > x_j)$$

Bài toán quy về tính $P(x_i > x_j)$ cho từng cặp $(i, j)$.

**Trường hợp $r_i \le r_j$:** Với mỗi giá trị $a$ của $x_i$ ($1 \le a \le r_i$), có $a - 1$ giá trị $x_j$ nhỏ hơn $a$. Tổng hợp:

$$P(x_i > x_j) = \frac{1}{r_i \cdot r_j} \sum_{a=1}^{r_i}(a-1) = \frac{r_i(r_i-1)}{2 \cdot r_i \cdot r_j} = \frac{r_i - 1}{2r_j}$$

**Trường hợp $r_i > r_j$:** Khi $x_i > r_j$ (xác suất $\frac{r_i - r_j}{r_i}$), $x_i$ chắc chắn lớn hơn $x_j$. Khi $x_i \le r_j$, bài toán quy về trường hợp cùng biên $r_j$:

$$P(x_i > x_j) = \frac{r_i - r_j}{r_i} + \frac{r_j}{r_i} \cdot \frac{r_j - 1}{2r_j} = \frac{2r_i - r_j - 1}{2r_i}$$

**Công thức tổng quát:**

$$P(x_i > x_j) = \frac{\max(0, r_i - r_j) \cdot r_j + \frac{\min(r_i, r_j)(\min(r_i, r_j) - 1)}{2}}{r_i \cdot r_j}$$

### Thuật toán

1. Đọc $n$ và mảng $r$.
2. Với mỗi cặp $(i, j)$ thỏa $i < j$, tính $P(x_i > x_j)$ bằng công thức trên.
3. Cộng tất cả xác suất và xuất kết quả làm tròn 6 chữ số thập phân.

### Ví dụ minh họa

$n = 3$, $r = [5, 2, 7]$.

| Cặp | $r_i, r_j$ | Trường hợp | $P(x_i > x_j)$ |
|-----|-----------|-----------|-----------------|
| (1,2) | 5, 2 | $r_i > r_j$ | $\frac{2 \cdot 5 - 2 - 1}{2 \cdot 5} = \frac{7}{10}$ |
| (1,3) | 5, 7 | $r_i \le r_j$ | $\frac{5-1}{2 \cdot 7} = \frac{2}{7}$ |
| (2,3) | 2, 7 | $r_i \le r_j$ | $\frac{2-1}{2 \cdot 7} = \frac{1}{14}$ |

$$E = \frac{7}{10} + \frac{2}{7} + \frac{1}{14} = \frac{37}{35} \approx 1.057143$$

## Độ phức tạp

- **Thời gian:** $O(n^2)$
- **Không gian:** $O(n)$

## Mã nguồn (Python)

[Mã nguồn](../code/Inversion%20Probability.py)
