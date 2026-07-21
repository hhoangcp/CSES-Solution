# Dynamic Range Sum Queries - Lời giải

**ID:** 1648 | **URL:** https://cses.fi/problemset/task/1648

## Hướng tiếp cận

### Tóm tắt đề bài

Cho mảng $n$ số nguyên, xử lý $q$ truy vấn:
1. Cập nhật giá trị tại vị trí $k$ thành $u$.
2. Tính tổng các phần tử trong đoạn $[a, b]$.

### Ý tưởng cốt lõi

Bài toán yêu cầu cả cập nhật điểm lẫn truy vấn tổng đoạn. **Cây phân đoạn** (segment tree) hỗ trợ cả hai thao tác trong $O(\log n)$. Mỗi lá lưu giá trị mảng tại vị trí đó; mỗi nút nội lưu tổng hai nút con. Do phép cộng có tính kết hợp — $\sum_{i=l}^{r} x_i = \bigl(\sum_{i=l}^{mid} x_i\bigr) + \bigl(\sum_{i=mid+1}^{r} x_i\bigr)$ — các nút nội luôn kết hợp đúng kết quả hai con, và bất biến này được bảo toàn sau mỗi lần cập nhật nhờ lan truyền từ lá đã sửa lên đến gốc.

Phần tử trung hòa của phép cộng là 0. Vì giá trị phần tử lên đến $10^9$ và đoạn có thể chứa tối đa $2 \cdot 10^5$ phần tử, tổng có thể đạt $2 \cdot 10^{14}$, cần dùng `long long` cho các nút cây phân đoạn để tránh tràn số.

### Thuật toán

1. **Xây dựng cây:** Khởi tạo tất cả nút bằng 0, sau đó chèn từng giá trị mảng bằng cập nhật điểm.
2. **Cập nhật điểm** ($x_k = u$): Đệ quy đến lá $k$, đặt giá trị mới $u$, rồi lan truyền lên: mỗi nút tổ tiên được tính lại bằng con trái + con phải. Chỉ $O(\log n)$ nút trên đường từ gốc đến lá bị thay đổi.
3. **Truy vấn đoạn** (tổng trên $[a, b]$): Đệ quy từ gốc. Tại nút quản lý $[l, r]$:
   - Nếu $[l, r]$ không giao $[a, b]$: trả về 0 (trung hòa).
   - Nếu $[l, r] \subseteq [a, b]$: trả về giá trị đã lưu.
   - Ngược lại: trả về truy vấn(con trái) + truy vấn(con phải).

### Ví dụ

Đầu vào:
```
8 4
3 2 4 5 1 1 5 3
2 1 4
2 5 6
1 3 1
2 1 4
```

- Truy vấn tổng $[1,4]$: $3 + 2 + 4 + 5 = 14$.
- Truy vấn tổng $[5,6]$: $1 + 1 = 2$.
- Cập nhật vị trí 3 thành 1: mảng trở thành $[3, 2, 1, 5, 1, 1, 5, 3]$.
- Truy vấn tổng $[1,4]$: $3 + 2 + 1 + 5 = 11$.

Kết quả:
```
14
2
11
```

## Độ phức tạp

- **Thời gian:** $O((n + q) \log n)$
- **Bộ nhớ:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Dynamic%20Range%20Sum%20Queries.cpp)
