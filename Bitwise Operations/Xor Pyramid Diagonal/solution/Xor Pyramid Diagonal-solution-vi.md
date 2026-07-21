# Xor Pyramid Diagonal - Lời giải

**ID:** 3194 | **URL:** https://cses.fi/problemset/task/3194

## Phương pháp

### Tóm tắt bài toán

Cho kim tự tháp XOR với hàng đáy $a_0, a_1, \ldots, a_{n-1}$, tìm phần tử ngoài cùng bên trái của mỗi hàng (từ đáy lên đỉnh).

### Ý tưởng chính

Trong kim tự tháp XOR, phần tử trái nhất của hàng $r$ (đánh số từ đáy) bằng $\bigoplus_{j=0}^{r} a_j \cdot [\binom{r}{j} \text{ lẻ}]$. Theo **định lý Lucas** trên GF(2), $\binom{r}{j}$ lẻ khi và chỉ khi mọi bit 1 của $j$ đều nằm trong $r$, tức $j$ là **mặt con** của $r$ ($j \subseteq r$). Vậy bài toán quy về tính $\text{left}[r] = \bigoplus_{j \subseteq r} a_j$ cho mọi $r$, chính là phép **biến đổi Zeta tập con** trên GF(2) — tính hiệu quả bằng SOS DP.

### Thuật toán

1. **Khởi tạo:** Đặt $dp[i] = a_i$ cho mọi $i$.
2. **SOS DP (biến đổi Zeta tập con):** Với mỗi vị trí bit $i$ từ 0 đến $h-1$ (với $h = \lceil \log_2 n \rceil$), và mỗi chỉ số $j$: nếu bit $i$ được đặt trong $j$, cập nhật $dp[j] \mathrel{\oplus}= dp[j \oplus 2^i]$.
3. **Kết quả:** $dp[r] = \text{left}[r]$ cho mỗi hàng $r$.

**Tại sao đúng:** Theo quy nạp trên bit $i$. Sau khi xử lý bit $i$, $dp[mask]$ chứa XOR của mọi $a_j$ với $j$ là mặt con của $mask$ xét đến bit $0$ đến $i$. Khi bit $i$ được đặt trong $mask$, việc XOR thêm $dp[mask \oplus 2^i]$ thêm đóng góp từ các mặt con có bit $i = 0$; các mặt con có bit $i = 1$ đã có sẵn. Sau $h$ bit, $dp[mask]$ tích lũy XOR mọi mặt con.

### Ví dụ minh họa

Đầu vào: $n = 8$, hàng đáy $[2, 10, 5, 12, 9, 5, 1, 5]$.

| $r$ | Nhị phân | Mặt con của $r$ | $\text{left}[r]$ |
|---|---|---|---|
| 0 | 000 | $\{0\}$ | $a_0 = 2$ |
| 1 | 001 | $\{0, 1\}$ | $2 \oplus 10 = 8$ |
| 2 | 010 | $\{0, 2\}$ | $2 \oplus 5 = 7$ |
| 3 | 011 | $\{0, 1, 2, 3\}$ | $2 \oplus 10 \oplus 5 \oplus 12 = 1$ |
| 4 | 100 | $\{0, 4\}$ | $2 \oplus 9 = 11$ |
| 5 | 101 | $\{0, 1, 4, 5\}$ | $2 \oplus 10 \oplus 9 \oplus 5 = 4$ |
| 6 | 110 | $\{0, 2, 4, 6\}$ | $2 \oplus 5 \oplus 9 \oplus 1 = 15$ |
| 7 | 111 | $\{0, 1, 2, 3, 4, 5, 6, 7\}$ | $2 \oplus 10 \oplus 5 \oplus 12 \oplus 9 \oplus 5 \oplus 1 \oplus 5 = 9$ |

Kết quả: `2 8 7 1 11 4 15 9`.

## Độ phức tạp

- **Thời gian:** $O(n \cdot h)$ với $h = \lceil \log_2 n \rceil$
- **Không gian:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Xor%20Pyramid%20Diagonal.cpp)
