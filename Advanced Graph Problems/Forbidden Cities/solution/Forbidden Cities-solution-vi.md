# Forbidden Cities - Lời giải

**ID:** 1705 | **URL:** https://cses.fi/problemset/task/1705

## Phương pháp

### Tóm tắt bài toán

Cho đồ thị vô hướng liên thông $n$ đỉnh, $m$ cạnh. Trả lời $q$ truy vấn: có đường đi từ $a$ đến $b$ không qua đỉnh $c$ không?

### Ý tưởng chính

Đỉnh $c$ ngăn cách $a$ và $b$ iff trong cây DFS, $c$ là tổ tiên của cả $a$ và $b$, và các cây con chứa $a$ và $b$ không có cạnh ngược vượt qua $c$. Theo tính chất DFS trên đồ thị vô hướng, loại $c$ chia đồ thị thành các thành phần tương ứng cây con của các con $c$. Đỉnh $a$ trong cây con của con $v$ của $c$ có thể ra bên ngoài không qua $c$ iff `low[v] < num[c]`, tức tồn tại cạnh ngược từ cây con đến tổ tiên của $c$. Nếu cả hai cây con chứa $a$ và $b$ đều có cạnh vượt, chúng vẫn liên thông sau khi loại $c$.

### Thuật toán

1. Gốc hóa đồ thị bằng DFS. Tính `num[u]`, `low[u]`, `out[u]`, và bảng binary lifting `P[u][i]`.
2. Định nghĩa `in(u, v)`: $u$ là tổ tiên của $v$ iff `num[u] <= num[v] && out[v] <= out[u]`.
3. Với mỗi truy vấn $(a, b, c)$:
   - Nếu $c = a$ hoặc $c = b$: NO.
   - Dùng binary lifting tìm con của $c$ là tổ tiên của $a$ (hoặc $b$).
   - Kiểm tra `low[]` của các cây con: nếu `low[child] < num[c]` thì tồn tại đường vòng qua $c$.

### Ví dụ minh họa

$n=5, m=6$, cạnh: 1-2, 1-3, 2-3, 2-4, 3-4, 4-5.

- Truy vấn $(1, 4, 2)$: có đường 1-3-4 tránh 2. YES.
- Truy vấn $(3, 5, 4)$: loại 4 cách ly 5. NO.
- Truy vấn $(3, 5, 2)$: đường 3-4-5 không qua 2. YES.

## Độ phức tạp

- **Thời gian:** $O((n + m) \log n + q \log n)$
- **Không gian:** $O(n \log n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Forbidden%20Cities.cpp)
