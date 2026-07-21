# Xor Pyramid Row - Lời giải

**ID:** 3195 | **URL:** https://cses.fi/problemset/task/3195

## Phương pháp

### Tóm tắt bài toán

Cho kim tự tháp XOR với hàng đáy $a_0, a_1, \ldots, a_{n-1}$, tìm tất cả phần tử trên hàng thứ $k$ từ đỉnh (hàng có $k$ phần tử).

### Ý tưởng chính

Đi lên $d = n - k$ bước từ đáy, phần tử thứ $i$ bằng $\bigoplus_{j \subseteq d} a_{i+j}$ (theo định lý Lucas: $\binom{d}{j}$ lẻ iff $j \subseteq d$). Thay vì $d$ bước tuần tự ($O(nd)$), phân tích $d$ thành tổng các lũy thừa 2 và áp dụng mỗi bước như một dịch XOR đơn lẻ, vì đi lên $2^s$ bước đơn giản là $a'[i] = a[i] \oplus a[i + 2^s]$ (mặt con duy nhất của $2^s$ là $\{0, 2^s\}$). Các dịch này giao hoán trên GF(2), nên thứ tự áp dụng bất kỳ đều cho kết quả đúng.

### Thuật toán

1. Tính $d = n - k$ (số bước từ hàng đáy).
2. Với mỗi bit $i$ từ 0 đến 17:
   - Nếu bit $i$ được đặt trong $d$: áp dụng dịch XOR khoảng cách $2^i$: $a[j] \mathrel{\oplus}= a[j + 2^i]$ cho mọi $j$ hợp lệ.
3. Xuất $k$ phần tử đầu tiên của $a$.

**Tại sao các dịch XOR kết hợp đúng:** Mỗi dịch tại bit $i$ thực hiện biến đổi tập con cho bit $i$. Vì các biến đổi này giao hoán trên GF(2), áp dụng các dịch tương ứng với mọi bit 1 của $d$ tương đương tính $\bigoplus_{j \subseteq d} a_{i+j}$ cho mỗi vị trí $i$.

### Ví dụ minh họa

Đầu vào: $n = 8$, $k = 5$, hàng đáy $[2, 10, 5, 12, 9, 5, 1, 5]$.

$d = 3 = 11_2$. Mặt con của 3: $\{0, 1, 2, 3\}$.

**Bit 0 (dịch 1):** $a[j] \oplus= a[j+1]$

| $j$ | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
|---|---|---|---|---|---|---|---|---|
| Trước | 2 | 10 | 5 | 12 | 9 | 5 | 1 | 5 |
| Sau | 8 | 15 | 9 | 5 | 12 | 4 | 4 | 5 |

**Bit 1 (dịch 2):** $a[j] \oplus= a[j+2]$

| $j$ | 0 | 1 | 2 | 3 | 4 |
|---|---|---|---|---|---|
| Trước | 8 | 15 | 9 | 5 | 12 |
| Sau | 1 | 10 | 5 | 1 | 8 |

5 phần tử đầu: `1 10 5 1 8`.

**Kiểm tra bằng công thức:** $\text{hàng}[i] = a_i \oplus a_{i+1} \oplus a_{i+2} \oplus a_{i+3}$ với $d = 3$:
- $2 \oplus 10 \oplus 5 \oplus 12 = 1$, $10 \oplus 5 \oplus 12 \oplus 9 = 10$, $5 \oplus 12 \oplus 9 \oplus 5 = 5$, $12 \oplus 9 \oplus 5 \oplus 1 = 1$, $9 \oplus 5 \oplus 1 \oplus 5 = 8$. $\checkmark$

## Độ phức tạp

- **Thời gian:** $O(n \cdot \log n)$ — tối đa $\log n$ bit, mỗi bit quét $O(n)$
- **Không gian:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Xor%20Pyramid%20Row.cpp)
