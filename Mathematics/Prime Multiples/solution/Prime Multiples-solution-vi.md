# Prime Multiples - Lời giải

**ID:** 2185 | **URL:** https://cses.fi/problemset/task/2185

## Phương pháp

### Tóm tắt bài toán

Cho $n$ ($n \le 10^{18}$) và $k$ số nguyên tố phân biệt $a_1, a_2, \ldots, a_k$ ($k \le 20$). Đếm số nguyên trong $[1, n]$ chia hết cho ít nhất một trong các số nguyên tố đã cho.

### Ý tưởng chính

Gọi $A_i$ là tập các số trong $[1, n]$ chia hết cho $a_i$. Theo **nguyên lý bao hàm - loại trừ**:

$$\left|\bigcup_{i=1}^{k} A_i\right| = \sum_{\emptyset \neq S \subseteq \{1,\ldots,k\}} (-1)^{|S|+1} \left\lfloor \frac{n}{\prod_{i \in S} a_i} \right\rfloor$$

Vì các $a_i$ là nguyên tố phân biệt, $\text{lcm}(S) = \prod_{i \in S} a_i$, và $\lfloor n / \text{lcm}(S) \rfloor$ đếm bội của tất cả $a_i \in S$.

**Tính đúng:** Phần tử $x$ chia hết cho đúng $t$ số nguyên tố xuất hiện trong $\binom{t}{j}$ tập con kích thước $j$ từ $t$ số đó. Tổng đóng góp: $\sum_{j=1}^{t} (-1)^{j+1} \binom{t}{j} = 1 - (1-1)^t = 1$. Mỗi phần tử hợp lệ được đếm đúng 1 lần.

Vì $k \le 20$, duyệt tất cả $2^k - 1$ tập con bằng bitmask. **Xử lý tràn số:** trước khi nhân thêm $a_{\text{next}}$ vào tích hiện tại $P$, kiểm tra $P > n / a_{\text{next}}$; nếu đúng thì $P \cdot a_{\text{next}} > n$ và đóng góp là 0.

### Thuật toán

1. Đọc $n$, $k$ và $k$ số nguyên tố.
2. Với mỗi bitmask từ $1$ đến $2^k - 1$: tính tích các số nguyên tố được chọn (có kiểm tra tràn), rồi cộng $(-1)^{|S|+1} \cdot \lfloor n / P \rfloor$ vào kết quả.
3. Xuất kết quả.

### Ví dụ minh họa

$n = 20$, $k = 2$, nguyên tố $= [2, 5]$.

| $S$ | $|S|$ | Dấu | $\prod a_i$ | $\lfloor 20/P \rfloor$ | Đóng góp |
|-----|-------|------|-------------|------------------------|----------|
| $\{1\}$ | 1 | $+$ | 2 | 10 | $+10$ |
| $\{2\}$ | 1 | $+$ | 5 | 4 | $+4$ |
| $\{1,2\}$ | 2 | $-$ | 10 | 2 | $-2$ |

Đáp án $= 10 + 4 - 2 = 12$ $\checkmark$.

12 số thỏa mãn: $\{2, 4, 5, 6, 8, 10, 12, 14, 15, 16, 18, 20\}$.

## Độ phức tạp

- **Thời gian:** $O(k \cdot 2^k)$
- **Không gian:** $O(k)$

## Mã nguồn (C++)

[Mã nguồn](../code/Prime%20Multiples.cpp)
