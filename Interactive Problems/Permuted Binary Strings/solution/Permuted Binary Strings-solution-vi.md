# Chuỗi nhị phân hoán vị - Lời giải

**ID:** 3228 | **URL:** https://cses.fi/problemset/task/3228

## Phương pháp

### Tóm tắt bài toán

Có một hoán vị ẩn $a_1, a_2, \dots, a_n$ của các số nguyên $1, 2, \dots, n$. Bạn có thể chọn chuỗi nhị phân $b_1 b_2 \dots b_n$ và nhận về chuỗi $b_{a_1} b_{a_2} \dots b_{a_n}$. Tìm hoán vị với tối đa 10 truy vấn.

### Ý tưởng chính

Mỗi truy vấn hoán vị các bit của chuỗi đầu vào theo hoán vị ẩn: phản hồi tại vị trí $j$ là $b_{a_j}$. Bằng cách thiết kế chuỗi đầu vào sao cho vị trí $i$ mã hóa một thuộc tính cụ thể của số nguyên $i$, phản hồi sẽ tiết lộ thuộc tính đó của từng $a_j$.

**Trích xuất từng bit:** Mỗi số nguyên trong $[1, n]$ có biểu diễn nhị phân duy nhất dùng $\lceil \log_2(n+1) \rceil \le 10$ bit. Với mỗi vị trí bit $l$, xây dựng chuỗi $s$ mà $s_i = \text{bit}_l(i)$. Khi truy vấn $s$, phản hồi $r_j = s_{a_j} = \text{bit}_l(a_j)$. Sau khi hỏi đủ các vị trí bit, mỗi $a_j$ được xác định hoàn toàn bằng cách ghép các bit.

**Tính tối ưu:** Phân biệt $n$ giá trị cần ít nhất $\lceil \log_2 n \rceil$ truy vấn. Thuật toán dùng đúng $\lceil \log_2(n+1) \rceil$ truy vấn, đạt tối ưu.

### Thuật toán

Với mỗi vị trí bit $l = 0, 1, \dots, \lceil \log_2(n+1) \rceil - 1$:

1. Xây dựng chuỗi $s$ độ dài $n$ với $s_i = \begin{cases} 1 & \text{nếu } i \wedge 2^l \neq 0 \\ 0 & \text{ngược lại} \end{cases}$.
2. Hỏi "? $s$", nhận phản hồi $r$.
3. Với mỗi $j$: nếu $r_j = 1$, bật bit $l$ của $a_j$.

Sau tất cả truy vấn, xuất "! $a_1\ a_2\ \dots\ a_n$".

### Ví dụ minh họa

$n = 3$, hoán vị ẩn $[1, 3, 2]$ (trùng ví dụ đề bài):

| Bit $l$ | Chuỗi $s$ | Phản hồi $r$ | Bit trích xuất |
|---------|-----------|--------------|----------------|
| 0 | `101` (bit 0 của 1,2,3) | `110` | $a_1$ bit 0 = 1, $a_2$ bit 0 = 1, $a_3$ bit 0 = 0 |
| 1 | `011` (bit 1 của 1,2,3) | `011` | $a_1$ bit 1 = 0, $a_2$ bit 1 = 1, $a_3$ bit 1 = 1 |

Tổng hợp: $a_1 = 0 \cdot 2 + 1 = 1$, $a_2 = 1 \cdot 2 + 1 = 3$, $a_3 = 1 \cdot 2 + 0 = 2$. Kết quả: $[1, 3, 2]$. ✓

## Độ phức tạp

- **Thời gian:** $O(n \log n)$
- **Bộ nhớ:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Permuted%20Binary%20Strings.cpp)
