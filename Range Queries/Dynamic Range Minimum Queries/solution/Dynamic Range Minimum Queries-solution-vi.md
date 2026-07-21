# Dynamic Range Minimum Queries - Lời giải

**ID:** 1649 | **URL:** https://cses.fi/problemset/task/1649

## Hướng tiếp cận

### Tóm tắt đề bài

Cho mảng $n$ số nguyên, xử lý $q$ truy vấn:
1. Cập nhật giá trị tại vị trí $k$ thành $u$.
2. Tìm giá trị nhỏ nhất trong đoạn $[a, b]$.

### Ý tưởng cốt lõi

Bài toán yêu cầu cả cập nhật điểm lẫn truy vấn minimum đoạn. **Cây phân đoạn** (segment tree) hỗ trợ cả hai thao tác trong $O(\log n)$. Mỗi lá lưu giá trị mảng tại vị trí đó; mỗi nút nội lưu $\min$(nút con trái, nút con phải). Do phép $\min$ có tính kết hợp — $\min_{i=l}^{r} x_i = \min\bigl(\min_{i=l}^{mid} x_i, \min_{i=mid+1}^{r} x_i\bigr)$ — các nút nội luôn kết hợp đúng kết quả hai con, và bất biến này được bảo toàn sau mỗi lần cập nhật nhờ lan truyền từ lá đã sửa lên đến gốc.

Phần tử trung hòa của phép $\min$ là $+\infty$; ta dùng $10^9+7$ vì mọi giá trị đều $\le 10^9$.

### Thuật toán

1. **Xây dựng cây:** Khởi tạo tất cả nút bằng $10^9+7$, sau đó chèn từng giá trị mảng bằng cập nhật điểm.
2. **Cập nhật điểm** ($x_k = u$): Đệ quy đến lá $k$, đặt giá trị mới $u$, rồi lan truyền lên: mỗi nút tổ tiên được tính lại $\min$(con trái, con phải). Chỉ $O(\log n)$ nút trên đường từ gốc đến lá bị thay đổi.
3. **Truy vấn đoạn** (tìm $\min$ trên $[a, b]$): Đệ quy từ gốc. Tại nút quản lý $[l, r]$:
   - Nếu $[l, r]$ không giao $[a, b]$: trả về $10^9+7$ (trung hòa).
   - Nếu $[l, r] \subseteq [a, b]$: trả về giá trị đã lưu.
   - Ngược lại: trả về $\min$(truy vấn con trái, truy vấn con phải).

### Ví dụ

Đầu vào:
```
8 4
3 2 4 5 1 1 5 3
2 1 4
2 5 6
1 2 3
2 1 4
```

- Truy vấn $\min[1,4]$: $\min(3, 2, 4, 5) = 2$.
- Truy vấn $\min[5,6]$: $\min(1, 1) = 1$.
- Cập nhật vị trí 2 thành 3: mảng trở thành $[3, 3, 4, 5, 1, 1, 5, 3]$. Lá $[2]$ đổi từ 2 sang 3; nút cha $[1,2]$ từ $\min(3,2)=2$ sang $\min(3,3)=3$; nút tổ tiên $[1,4]$ từ 2 sang 3.
- Truy vấn $\min[1,4]$: $\min(3, 3, 4, 5) = 3$.

Kết quả:
```
2
1
3
```

## Độ phức tạp

- **Thời gian:** $O((n + q) \log n)$
- **Bộ nhớ:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Dynamic%20Range%20Minimum%20Queries.cpp)
