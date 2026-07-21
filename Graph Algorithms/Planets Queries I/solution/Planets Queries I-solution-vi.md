# Truy Vấn Hành Tinh I - Lời giải

**ID:** 1750 | **URL:** https://cses.fi/problemset/task/1750

## Phương pháp

### Tóm tắt bài toán

Cho đồ thị hàm (mỗi đỉnh đúng một cạnh ra) trên $n$ đỉnh, xử lý $q$ truy vấn: từ đỉnh $x$, đỉnh nào được đến sau $k$ bước?

### Ý tưởng chính

Vì $k$ có thể lên tới $10^9$, không thể mô phỏng từng bước. **Nhảy đôi** (binary lifting) tiền xử lý bảng $\text{up}[u][i]$ = đỉnh đến từ $u$ sau $2^i$ bước. Công thức $\text{up}[u][i] = \text{up}[\text{up}[u][i-1]][i-1]$ đúng vì nhảy $2^i$ bước tương đương hai lần nhảy $2^{i-1}$ liên tiếp, và đường đi trong đồ thị hàm là duy nhất — thứ tự nhảy không ảnh hưởng kết quả. Vì $k < 2^{30}$, chỉ cần 30 mức.

Mỗi truy vấn phân tích $k$ sang biểu diễn nhị phân và áp dụng các bước nhảy tương ứng: với mỗi bit $i$ được bật của $k$, cập nhật $x \leftarrow \text{up}[x][i]$. Tổng số bước nhảy đúng bằng $k$ theo phân tích nhị phân.

### Thuật toán

1. Đọc đầu vào. Đặt $\text{up}[u][0] = t_u$ với mọi $u$.
2. Với $i = 1$ đến $30$: $\text{up}[u][i] = \text{up}[\text{up}[u][i-1]][i-1]$ với mọi $u$.
3. Với mỗi truy vấn $(x, k)$: với mỗi bit $i$ từ 30 xuống 0, nếu bit $i$ của $k$ được bật, $x \leftarrow \text{up}[x][i]$. Xuất $x$.

### Ví dụ minh họa

Input:
```
4 3
2 1 1 4
1 2
3 4
4 1
```

Máy dịch chuyển: $1 \to 2$, $2 \to 1$, $3 \to 1$, $4 \to 4$.

| $u$ | up[u][0] | up[u][1] | up[u][2] |
|-----|----------|----------|----------|
| 1   | 2        | 1        | 1        |
| 2   | 1        | 2        | 2        |
| 3   | 1        | 2        | 2        |
| 4   | 4        | 4        | 4        |

- Truy vấn $(1, 2)$: $k = 10_2$, bit 1 bật. $x = \text{up}[1][1] = 1$. **Kết quả: 1**.
- Truy vấn $(3, 4)$: $k = 100_2$, bit 2 bật. $x = \text{up}[3][2] = 2$. **Kết quả: 2**.
- Truy vấn $(4, 1)$: $k = 1_2$, bit 0 bật. $x = \text{up}[4][0] = 4$. **Kết quả: 4**.

## Độ phức tạp

- **Thời gian:** $O((n + q) \log K)$ với $K = 10^9$
- **Không gian:** $O(n \log K)$

## Mã nguồn (C++)

[Mã nguồn](../code/Planets%20Queries%20I.cpp)
