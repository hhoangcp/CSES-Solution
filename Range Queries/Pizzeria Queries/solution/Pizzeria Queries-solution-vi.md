# Pizzeria Queries - Lời giải

**ID:** 2206 | **URL:** https://cses.fi/problemset/task/2206

## Hướng tiếp cận

### Tóm tắt đề bài

Có $n$ tòa nhà trên phố, giá pizza ở tòa $a$ là $p_a$. Đặt từ tòa $a$ giao đến tòa $b$ tốn $p_a + |a - b|$. Xử lý $q$ truy vấn:
1. Cập nhật $p_k$ thành $x$.
2. Tìm chi phí thấp nhất khi đặt pizza giao đến tòa $k$.

### Ý tưởng cốt lõi

Duyệt tuyến tính cho mỗi truy vấn loại 2 tốn $O(n)$, tổng cộng $O(nq)$ — quá chậm. Nút thắt nằm ở dấu trị tuyệt đối $|a - k|$. Loại bỏ bằng cách tách theo vị trí tương đối:

- **$a \le k$** (bên trái): $|a - k| = k - a$, suy ra chi phí $= (p_a - a) + k$. Vì $k$ là hằng số, $\min_{1 \le a \le k}(p_a + |a - k|) = \min_{1 \le a \le k}(p_a - a) + k$.
- **$a \ge k$** (bên phải): $|a - k| = a - k$, suy ra chi phí $= (p_a + a) - k$. Vì $k$ là hằng số, $\min_{k \le a \le n}(p_a + |a - k|) = \min_{k \le a \le n}(p_a + a) - k$.

Mọi tòa nhà thuộc ít nhất một miền (tòa $k$ thuộc cả hai), nên $\{1, \dots, n\} = \{a \mid 1 \le a \le k\} \cup \{a \mid k \le a \le n\}$. Theo tính chất phân phối của $\min$ trên phép hợp:

$$\min_{a} (p_a + |a - k|) = \min\left(\min_{1 \le a \le k}(p_a - a) + k,\min_{k \le a \le n}(p_a + a) - k\right)$$

Cả $(p_a - a)$ và $(p_a + a)$ chỉ phụ thuộc vào tòa $a$, không phụ thuộc $k$, nên xây hai cây phân đoạn lưu minimum: **Down** lưu $d_i = p_i - i$ (cho miền trái); **Up** lưu $u_i = p_i + i$ (cho miền phải). Cập nhật đơn giản vì thay đổi $p_k$ chỉ ảnh hưởng vị trí $k$ trên cả hai cây.

### Thuật toán

1. **Xây dựng** hai cây phân đoạn min: Down với $d_i = p_i - i$, Up với $u_i = p_i + i$.
2. **Cập nhật** (loại 1): Đặt Down[$k$] $= x - k$ và Up[$k$] $= x + k$.
3. **Truy vấn** (loại 2): Trả về $\min(\text{Down.query}(1, k) + k,\text{Up.query}(k, n) - k)$.

### Ví dụ minh họa

Đầu vào:
```
6 3
8 6 4 5 7 5
2 2
1 5 1
2 2
```

Giá: $[8, 6, 4, 5, 7, 5]$. Down: $[7, 4, 1, 1, 2, -1]$. Up: $[9, 8, 7, 9, 12, 11]$.

- Truy vấn tòa 2: Down.query(1,2) $= 4$, chi phí trái $= 4 + 2 = 6$; Up.query(2,6) $= 7$, chi phí phải $= 7 - 2 = 5$. Đáp án $= \min(6, 5) = 5$ (đặt từ tòa 3: $4 + |3-2| = 5$).
- Cập nhật tòa 5 thành giá 1: Down[5] $= 1 - 5 = -4$; Up[5] $= 1 + 5 = 6$.
- Truy vấn tòa 2: Down.query(1,2) $= 4$, chi phí trái $= 6$; Up.query(2,6) $= \min(8,7,9,6,11) = 6$, chi phí phải $= 6 - 2 = 4$. Đáp án $= \min(6, 4) = 4$ (đặt từ tòa 5: $1 + |5-2| = 4$).

Kết quả:
```
5
4
```

## Độ phức tạp

- **Thời gian:** $O((n + q) \log n)$
- **Bộ nhớ:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Pizzeria%20Queries.cpp)
