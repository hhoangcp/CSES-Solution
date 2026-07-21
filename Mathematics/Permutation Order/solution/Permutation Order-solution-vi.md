# Permutation Order - Lời giải

**ID:** 3397 | **URL:** https://cses.fi/problemset/task/3397

## Phương pháp

### Tóm tắt bài toán

Xử lý hai loại truy vấn:
1. Cho $n$ và $k$, tìm hoán vị thứ $k$ (theo thứ tự từ điển) của $\{1, 2, \ldots, n\}$.
2. Cho $n$ và một hoán vị, tìm thứ hạng $k$ của hoán vị đó.

### Ý tưởng chính

Mọi hoán vị $n$ phần tử có thể mã hóa duy nhất bằng dãy $(d_0, d_1, \ldots, d_{n-1})$ gọi là **factoradic**, với $0 \le d_i \le n - 1 - i$ và $d_i$ đếm số phần tử chưa dùng nhỏ hơn phần tử đặt tại vị trí $i$. Thứ hạng $k$ (0-indexed) phân rã thành:

$$k = d_0 \cdot (n-1)! + d_1 \cdot (n-2)! + \cdots + d_{n-1} \cdot 0!$$

Nguyên lý hoạt động: sau khi cố định tiền tố dài $i+1$ phần tử, còn đúng $(n-1-i)!$ cách sắp xếp các phần tử còn lại. Do đó, nếu có $c_i$ phần tử chưa dùng nhỏ hơn phần tử đặt tại vị trí $i$, thì đúng $c_i \cdot (n-1-i)!$ hoán vị bị bỏ qua.

**Loại 1 (thứ hạng → hoán vị):** Giảm $k$ đi 1 (chuyển sang 0-indexed). Với mỗi vị trí $i$: tính $d_i = \lfloor k / (n-1-i)! \rfloor$, cập nhật $k \leftarrow k \bmod (n-1-i)!$, rồi chọn phần tử chưa dùng thứ $d_i$ (0-indexed).

**Loại 2 (hoán vị → thứ hạng):** Với mỗi vị trí $i$: đếm $c_i$ phần tử chưa dùng nhỏ hơn $a[i]$, cộng $c_i \cdot (n-1-i)!$ vào kết quả, đánh dấu $a[i]$ đã dùng. Cuối cùng cộng 1 (chuyển sang 1-indexed).

### Thuật toán

1. Tính trước giai thừa đến $20!$.
2. Với truy vấn Loại 1: phân rã factoradic và chọn phần tử chưa dùng.
3. Với truy vấn Loại 2: tích lũy $c_i \cdot (n-1-i)!$ tại mỗi vị trí.

### Ví dụ minh họa

$n = 4$, giai thừa: $3! = 6, 2! = 2, 1! = 1, 0! = 1$.

**Loại 1: $k = 2$** (0-indexed: $k = 1$). Chưa dùng: $\{1,2,3,4\}$.

| $i$ | $d_i = \lfloor k / (n{-}1{-}i)! \rfloor$ | $k$ sau mod | Phần tử |
|-----|------------------------------------------|-------------|---------|
| 0 | $\lfloor 1/6 \rfloor = 0$ | 1 | Phần tử chưa dùng thứ 0 = **1** |
| 1 | $\lfloor 1/2 \rfloor = 0$ | 1 | Phần tử chưa dùng thứ 0 = **2** |
| 2 | $\lfloor 1/1 \rfloor = 1$ | 0 | Phần tử chưa dùng thứ 1 = **4** |
| 3 | 0 | 0 | Cuối cùng = **3** |

Kết quả: `1 2 4 3` $\checkmark$

**Loại 2: hoán vị `1 2 4 3`**. $ans = 0$.

| $i$ | $a[i]$ | $c_i$ (chưa dùng < $a[i]$) | Đóng góp | $ans$ |
|-----|--------|----------------------------|----------|-------|
| 0 | 1 | 0 | $0 \cdot 6$ | 0 |
| 1 | 2 | 0 | $0 \cdot 2$ | 0 |
| 2 | 4 | 1 (phần tử 3) | $1 \cdot 1$ | 1 |
| 3 | 3 | 0 | $0 \cdot 1$ | 1 |

Thứ hạng = $1 + 1 = 2$ $\checkmark$

## Độ phức tạp

- **Thời gian:** $O(n^2)$ mỗi truy vấn (quét tuyến tính tìm phần tử chưa dùng)
- **Không gian:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Permutation%20Order.cpp)
