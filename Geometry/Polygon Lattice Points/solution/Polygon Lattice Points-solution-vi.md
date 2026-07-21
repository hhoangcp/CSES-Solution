# Polygon Lattice Points - Lời giải

**ID:** 2193 | **URL:** https://cses.fi/problemset/task/2193

## Phương pháp

### Tóm tắt bài toán

Cho đa giác đơn có các đỉnh nguyên, đếm số điểm lưới nằm bên trong ($I$) và trên biên ($B$) của đa giác.

### Ý tưởng chính

Sử dụng định lý Pick, liên hệ diện tích $A$, số điểm lưới bên trong $I$ và số điểm lưới trên biên $B$:

$$A = I + \frac{B}{2} - 1 \quad\Longrightarrow\quad I = \frac{2A - B + 2}{2}$$

Vậy ta cần hai đại lượng: $2A$ (tính bằng công thức Shoelace) và $B$ (tính bằng tổng điểm lưới trên mỗi cạnh).

**Số điểm trên biên $B$:** Số điểm lưới trên đoạn từ $(x_1, y_1)$ đến $(x_2, y_2)$ với đầu nguyên (bao gồm cả hai đầu) là $\gcd(|x_2 - x_1|, |y_2 - y_1|) + 1$. Điểm $(x, y)$ nằm trên đoạn từ $(0, 0)$ đến $(a, b)$ khi và chỉ khi $x = ta, y = tb$ với $t \in (0, 1]$. Để $x, y$ nguyên, $t$ phải có dạng $k/d$ với $d$ chia hết cả $a$ và $b$, cho đúng $\gcd(|a|, |b|)$ giá trị $t$ hợp lệ. Để tránh đếm trùng đỉnh chung, mỗi cạnh đóng góp $\gcd(|\Delta x|, |\Delta y|)$ (số điểm trừ đi 1 đầu mút), rồi $B = \sum_{\text{cạnh}} \gcd(|\Delta x|, |\Delta y|)$.

**Hai lần diện tích $S_2$:** Công thức Shoelace: $S_2 = \left|\sum_{i=1}^{n} (x_i - x_{i-1})(y_i + y_{i-1})\right|$ (chỉ số vòng).

**Số điểm bên trong $I$:** $I = (S_2 + 2 - B) / 2$.

### Thuật toán

1. Khởi tạo $S_2 = 0$, $B = 0$.
2. Với mỗi $i$ từ 1 đến $n$ (với $x_0 = x_n$, $y_0 = y_n$):
   - $S_2 \mathrel{+}= (x_i - x_{i-1})(y_i + y_{i-1})$.
   - $B \mathrel{+}= \gcd(|x_i - x_{i-1}|, |y_i - y_{i-1}|)$.
3. $S_2 = |S_2|$, $I = (S_2 + 2 - B) / 2$.
4. Xuất $I$ và $B$.

### Ví dụ minh họa

Đa giác: $(1,1), (5,3), (3,5), (1,4)$.

| $i$ | $(x_i - x_{i-1})(y_i + y_{i-1})$ | $\gcd(|\Delta x|, |\Delta y|)$ |
|-----|-------------------------------------|----------------------------------|
| 1 | $(1-1)(1+4) = 0$ | $\gcd(0, 3) = 3$ |
| 2 | $(5-1)(3+1) = 16$ | $\gcd(4, 2) = 2$ |
| 3 | $(3-5)(5+3) = -16$ | $\gcd(2, 2) = 2$ |
| 4 | $(1-3)(4+5) = -18$ | $\gcd(2, 1) = 1$ |

$S_2 = |0 + 16 - 16 - 18| = 18$. $B = 3 + 2 + 2 + 1 = 8$. $I = (18 + 2 - 8) / 2 = 6$.

Kết quả: `6 8`.

## Độ phức tạp

- **Thời gian:** $O(n \log(\max |x_i|))$
- **Không gian:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Polygon%20Lattice%20Points.cpp)
